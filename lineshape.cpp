#include "lineshape.h"

LineShape::LineShape(const QPoint &start, const QPoint &end)
    : Shape(start,end)
{
}

void LineShape::draw(QPainter &painter) const
{
    painter.drawLine(startPoint, endPoint);
}