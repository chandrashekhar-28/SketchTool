#ifndef CANVAS_H
#define CANVAS_H

#include "shape.h"
#include <QVector>
#include <QPoint>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QWidget>

enum class DrawMode
{
    Line, Rectangle, Circle
};

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);

    void setDrawMode(DrawMode Mode);

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
    DrawMode currentMode = DrawMode::Line;

signals:
};

#endif // CANVAS_H