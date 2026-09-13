#include "rectangleshape.h"

RectangleShape::RectangleShape(const QPoint &start, const QPoint &end)
    :Shape(start, end)
{
}

void RectangleShape::draw(QPainter &painter) const
{
    painter.drawRect(QRect(startPoint, endPoint));
}