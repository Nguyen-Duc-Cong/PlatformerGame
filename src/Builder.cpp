#include "Builder.h"
#include "Constances.h"

b2PolygonShape* Builder::buildPolygon(const std::vector<tmx::Vector2f>& points)
{
    auto    n = points.size();
    b2Vec2* v = new b2Vec2[n];
    for (std::size_t i = 0; i < n; ++i)
    {
        auto  point = points[i];
        float x     = (point.x) / Constances::PPM;
        float y     = (point.y) / Constances::PPM;
        v[i].Set(x, y);
    }
    b2PolygonShape* polygon = new b2PolygonShape();
    polygon->Set(v, n);
    delete[] v;
    return polygon;
}

b2PolygonShape* Builder::buildRectangle(const tmx::Rectangle<float>& rect)
{
    b2PolygonShape* polygon = new b2PolygonShape();
    polygon->SetAsBox(rect.width / 2.f / Constances::PPM,
                      rect.height / 2.f / Constances::PPM,
                      b2Vec2(rect.width / 2.f / Constances::PPM,
                             rect.height / 2.f / Constances::PPM),
                      0.f);
    return polygon;
}

b2Shape* Builder::buildShape(const tmx::Object& object)
{
    switch (object.getShape())
    {
    case tmx::Object::Shape::Rectangle:
        return buildRectangle(object.getAABB());
        break;
    case tmx::Object::Shape::Polygon: return buildPolygon(object.getPoints());
    default: return nullptr;
    }
}