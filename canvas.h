#include "shape.h"
#include <QVector>
#include <QPoint>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QWidget>
#ifndef CANVAS_H
#define CANVAS_H

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
    QVector<Shape*> shapes;
    QPoint startPoint;
    QPoint currentPoint;
    bool isDrawing = false;

signals:
};

#endif // CANVAS_H