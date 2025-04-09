// radarwidget.cpp
#include "radarwidget.h"
#include <QPainter>

RadarWidget::RadarWidget(QWidget *parent) : QWidget(parent) {}

void RadarWidget::setStats(int buts, int passes, int cartonsJ, int cartonsR) {
    m_buts = buts;
    m_passes = passes;
    m_cartonsJ = cartonsJ;
    m_cartonsR = cartonsR;
    update(); // Force le redessin
}


void RadarWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Dimensions
    int size = qMin(width(), height()) - 20;
    int centerX = width() / 2;
    int centerY = height() / 2;

    // Valeurs maximales pour chaque statistique
    const float MAX_BUTS = 20.0f;
    const float MAX_PASSES = 20.0f;
    const float MAX_CARTONS_J = 10.0f;
    const float MAX_CARTONS_R = 10.0f;

    // Normalisation des valeurs (limitée à 1.0 si supérieure au max)
    float butsNorm = qMin(m_buts / MAX_BUTS, 1.0f);
    float passesNorm = qMin(m_passes / MAX_PASSES, 1.0f);
    float cartonsJNorm = qMin(m_cartonsJ / MAX_CARTONS_J, 1.0f);
    float cartonsRNorm = qMin(m_cartonsR / MAX_CARTONS_R, 1.0f);

    // Dessine les axes
    painter.setPen(Qt::gray);
    for (int i = 1; i <= 5; ++i) {
        int radius = size * i / 10;
        painter.drawEllipse(QPoint(centerX, centerY), radius, radius);
    }

    // Dessine les lignes d'axes
    QStringList labels = {"Buts", "Passes", "Cartons J", "Cartons R"};
    for (int i = 0; i < 4; ++i) {
        double angle = 2 * M_PI * i / 4;
        int x = centerX + size/2 * cos(angle);
        int y = centerY - size/2 * sin(angle);
        painter.drawLine(centerX, centerY, x, y);
        painter.drawText(x, y, labels[i]);
    }

    // Dessine les données (avec valeurs normalisées)
    QPolygonF polygon;
    polygon << QPointF(centerX, centerY - size/2 * butsNorm)
            << QPointF(centerX + size/2 * passesNorm, centerY)
            << QPointF(centerX, centerY + size/2 * cartonsJNorm)
            << QPointF(centerX - size/2 * cartonsRNorm, centerY);

    painter.setPen(Qt::blue);
    painter.setBrush(QColor(0, 0, 255, 50));
    painter.drawPolygon(polygon);


}
