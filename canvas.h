#include <QVector>
#include <QLine>
#include <QPoint>
#include <QMouseEvent>
#include <QPaintEvent>
#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QVector<QLine> lines;
    QPoint startPoint;
    QPoint currentPoint;
    bool isDrawing = false;

signals:
};

#endif // CANVAS_H