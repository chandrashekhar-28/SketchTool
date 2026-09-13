#include "canvas.h"
#include "lineshape.h"
#include "rectangleshape.h"
#include "circleshape.h"
#include <QPainter>
#include <QtGlobal>

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize (600, 400);
}

void Canvas::setDrawMode(DrawMode mode)
{
    currentMode = mode;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::white, 3));

    for (Shape* shape : std::as_const(shapes))
    {
        shape->draw(painter);
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

        Shape *newShape = nullptr;
        switch (currentMode)
        {
        case DrawMode::Line:
            newShape = new LineShape(startPoint, currentPoint);
            break;
        case DrawMode::Rectangle:
            newShape = new RectangleShape(startPoint, currentPoint);
            break;
            case DrawMode::Circle:
            newShape = new CircleShape(startPoint, currentPoint);
            break;
        }

        if (newShape)
            {
                shapes.append(newShape);
            }

        isDrawing = false;
        update();
    }
}