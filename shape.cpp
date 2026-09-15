#include "shape.h"

Shape::Shape(ShapeType type, const QPoint &start, const QPoint &end)
    : shapeType(type), startPoint(start), endPoint(end)
{
}

Shape::~Shape()
{
}

ShapeType Shape::type() const
{
    return shapeType;
}

QJsonObject Shape::toJson() const
{
    QJsonObject obj;
    obj["type"] = static_cast<int>(shapeType);
    obj["x1"] = startPoint.x();
    obj["y1"] = startPoint.y();
    obj["x2"] = endPoint.x();
    obj["y2"] = endPoint.y();
    return obj;
}