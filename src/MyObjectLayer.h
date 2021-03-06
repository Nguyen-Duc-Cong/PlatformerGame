#ifndef MY_OBJECT_LAYER_H
#define MY_OBJECT_LAYER_H
#include "ObjectLayer.h"
#include "tmxlite/ObjectGroup.hpp"
class MyObjectLayer : public ObjectLayer
{
  public:
    static MyObjectLayer* Create(const tmx::ObjectGroup& data);

  private:
    MyObjectLayer() {}
    bool Init(const tmx::ObjectGroup& data);
};
#endif // MY_OBJECT_LAYER_H
