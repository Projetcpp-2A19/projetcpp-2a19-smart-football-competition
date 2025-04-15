import sys
import cv2
import numpy as np
from ultralytics import YOLO
from scipy.spatial import distance

if len(sys.argv) < 3:
    print("Usage: python aimodel.py <video_path> <model_path>")
    sys.exit(1)

media_path = sys.argv[1]
model_path = sys.argv[2]
model = YOLO(model_path)

def extract_tshirt_region(img, bbox):
    x1, y1, x2, y2 = bbox
    height = y2 - y1
    start_y = y1 + height // 3
    end_y = y1 + 2 * height // 3
    region = img[start_y:end_y, x1:x2]
    if region.shape[0] > 0 and region.shape[1] > 0:
        return region
    return None

def detect_football(results):
    for result in results:
        for box in result.boxes:
            if int(box.cls[0]) == 32:
                return list(map(int, box.xyxy[0]))
    return None

frame_count = 0
team_colors = None
team1_possession = 0
team2_possession = 0

def process_frame(img):
    global frame_count, team_colors, team1_possession, team2_possession
    results = model(img)
    players = []
    tshirt_colors = []

    for result in results:
        for box in result.boxes:
            if int(box.cls[0]) == 0:
                x1, y1, x2, y2 = map(int, box.xyxy[0])
                if (x2 - x1) < 20 or (y2 - y1) < 20:
                    continue
                tshirt_region = extract_tshirt_region(img, (x1, y1, x2, y2))
                if tshirt_region is not None:
                    avg_color = np.mean(tshirt_region, axis=(0, 1))[:3].astype(np.float32)
                    if avg_color.shape == (3,):
                        players.append((x1, y1, x2, y2, avg_color))
                        tshirt_colors.append(avg_color)

    if frame_count == 0 and len(tshirt_colors) >= 2:
        colors = np.array(tshirt_colors, dtype=np.float32)
        _, labels, centers = cv2.kmeans(colors, 2, None,
                                        (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 1.0),
                                        10, cv2.KMEANS_RANDOM_CENTERS)
        team_colors = np.array(centers)

    team1, team2 = [], []
    if team_colors is not None:
        for (x1, y1, x2, y2, avg_color) in players:
            dist1 = distance.euclidean(avg_color, team_colors[0])
            dist2 = distance.euclidean(avg_color, team_colors[1])
            if dist1 < dist2:
                team1.append((x1, y1, x2, y2, avg_color))
            else:
                team2.append((x1, y1, x2, y2, avg_color))

    ball_bbox = detect_football(results)

    if ball_bbox and len(ball_bbox) == 4:
        bx1, by1, bx2, by2 = ball_bbox
        ball_center = ((bx1 + bx2) // 2, (by1 + by2) // 2)

        closest_dist = float('inf')
        closest_team = None
        for (x1, y1, x2, y2, _) in team1 + team2:
            player_center = ((x1 + x2) // 2, (y1 + y2) // 2)
            dist = distance.euclidean(ball_center, player_center)
            if dist < closest_dist:
                closest_dist = dist
                closest_team = 'team1' if (x1, y1, x2, y2, _) in team1 else 'team2'

        if closest_team == 'team1':
            team1_possession += 1
        elif closest_team == 'team2':
            team2_possession += 1

        cv2.rectangle(img, (bx1, by1), (bx2, by2), (0, 0, 255), 2)
        cv2.putText(img, "Football", (bx1, by1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)

    for (x1, y1, x2, y2, _) in team1:
        cv2.rectangle(img, (x1, y1), (x2, y2), (255, 0, 0), 2)
        cv2.putText(img, "Team 1", (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 0, 0), 2)
    for (x1, y1, x2, y2, _) in team2:
        cv2.rectangle(img, (x1, y1), (x2, y2), (0, 255, 0), 2)
        cv2.putText(img, "Team 2", (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)

    total_possession = team1_possession + team2_possession
    if total_possession > 0:
        team1_percent = int((team1_possession / total_possession) * 100)
        team2_percent = 100 - team1_percent
    else:
        team1_percent = team2_percent = 50

    font = cv2.FONT_HERSHEY_SIMPLEX
    cv2.putText(img, f"Team 1 Possession: {team1_percent}%", (20, 40), font, 0.8, (255, 0, 0), 2)
    cv2.putText(img, f"Team 2 Possession: {team2_percent}%", (400, 40), font, 0.8, (0, 255, 0), 2)

    frame_count += 1
    return img

cap = cv2.VideoCapture(media_path)
if not cap.isOpened():
    print("Error: Unable to open video.")
    sys.exit(1)

while cap.isOpened():
    ret, img = cap.read()
    if not ret:
        break

    img = process_frame(img)
    cv2.imshow("Football AI - Possession Tracker", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
