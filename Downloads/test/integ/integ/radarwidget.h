#ifndef RADARWIDGET_H
#define RADARWIDGET_H

#include <QWidget>

class RadarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RadarWidget(QWidget *parent = nullptr);
    void setStats(int buts, int passes, int cartonsJ, int cartonsR);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_buts = 0;
    int m_passes = 0;
    int m_cartonsJ = 0;
    int m_cartonsR = 0;
};

#endif // RADARWIDGET_H
