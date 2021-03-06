#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "ImageLayer.h"
#include "Layer.h"
namespace tmx
{
class ImageLayer;
}
class Background : public ImageLayer
{
  public:
    static Background* Create(const tmx::ImageLayer& data);

	~Background();

    bool Init(const tmx::ImageLayer& imageLayerData);
    void Tick(float deltaTime) override;

  private:
    Background(); 
    float m_parallax;
    float m_initialPositionX;

    SDL_Texture* m_texture;
};
#endif // BACKGROUND_H
