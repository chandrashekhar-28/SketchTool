#include "lineshape.h"

LineShape::LineShape(const QPoint &start, const QPoint &end)
    : Shape(ShapeType::Line, start,end)
{
}

void LineShape::draw(QPainter &painter) const
{
    painter.drawLine(startPoint, endPoint);
}