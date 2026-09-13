#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "shape.h"

class CircleShape : public Shape
{
public:
    CircleShape(const QPoint &start, const QPoint &end);

    void draw(QPainter &painter) const override;
};

#endif // CIRCLESHAPE_H