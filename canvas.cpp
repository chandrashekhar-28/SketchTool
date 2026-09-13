#include "canvas.h"
#include <QPainter>
#include <QtGlobal>

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize (600, 400);
}

void Canvas::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::white, 3));

    for (const QLine &line :  std::as_const(lines))
    {
        painter.drawLine(line);
    }

    if (isDrawing)
    {
        painter.drawLine(startPoint, currentPoint);
    }
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    startPoint = event->pos();
    currentPoint = startPoint;
    isDrawing = true;
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if (isDrawing)
    {
        currentPoint = event->pos();
        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if (isDrawing)
    {
        currentPoint = event->pos();
        lines.append(QLine(startPoint, currentPoint));
        isDrawing = false;
        update();
    }
}