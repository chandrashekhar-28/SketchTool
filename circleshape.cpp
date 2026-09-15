#include "circleshape.h"

CircleShape::CircleShape(const QPoint &start, const QPoint &end)
    : Shape(ShapeType::Circle, start, end)
{
}

void CircleShape::draw(QPainter &painter) const
{
    painter.drawEllipse(QRect(startPoint, endPoint));
}
