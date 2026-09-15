#include "canvas.h"
#include "lineshape.h"
#include "rectangleshape.h"
#include "circleshape.h"
#include <QPainter>
#include <QtGlobal>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(600, 400);
}

void Canvas::setDrawMode(DrawMode mode)
{
    currentMode = mode;
}

void Canvas::undo()
{
    if (!shapes.empty())
    {
        shapes.pop_back();
        update();
    }
}

void Canvas::clear()
{
    shapes.clear();
    update();
}

void Canvas::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::white, 3));

    for (const auto &shape : std::as_const(shapes))
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

        std::unique_ptr<Shape> newShape;
        switch (currentMode)
        {
        case DrawMode::Line:
            newShape = std::make_unique<LineShape>(startPoint, currentPoint);
            break;
        case DrawMode::Rectangle:
            newShape = std::make_unique<RectangleShape>(startPoint, currentPoint);
            break;
        case DrawMode::Circle:
            newShape = std::make_unique<CircleShape>(startPoint, currentPoint);
            break;
        }

        if (newShape)
        {
            shapes.push_back(std::move(newShape));
        }

        isDrawing = false;
        update();
    }
}

bool Canvas::saveToFile(const QString &filePath)
{
    QJsonArray array;
    for (const auto &shape : std::as_const(shapes))
    {
        array.append(shape->toJson());
    }

    QJsonDocument doc(array);

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly))
    {
        return false;
    }
    file.write(doc.toJson());
    file.close();
    return true;
}

bool Canvas::loadFromFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray())
    {
        return false;
    }

    QJsonArray array = doc.array();
    shapes.clear();

    for (const QJsonValue &val : std::as_const(array))
    {
        QJsonObject obj = val.toObject();
        ShapeType type = static_cast<ShapeType>(obj["type"].toInt());
        QPoint start(obj["x1"].toInt(), obj["y1"].toInt());
        QPoint end(obj["x2"].toInt(), obj["y2"].toInt());

        std::unique_ptr<Shape> shape;
        switch (type)
        {
        case ShapeType::Line:
            shape = std::make_unique<LineShape>(start, end);
            break;
        case ShapeType::Rectangle:
            shape = std::make_unique<RectangleShape>(start, end);
            break;
        case ShapeType::Circle:
            shape = std::make_unique<CircleShape>(start, end);
            break;
        }

        if (shape)
        {
            shapes.push_back(std::move(shape));
        }
    }

    update();
    return true;
}