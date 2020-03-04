#ifndef NT_TEXTURE_REGION_H
#define NT_TEXTURE_REGION_H
#include "SDL2/SDL.h"
#include "SDL_render.h"
struct NTTextureRegion {
  SDL_Texture *texture;
  SDL_Rect rect;

  NTTextureRegion();

  NTTextureRegion(SDL_Texture *_texture);

  NTTextureRegion(SDL_Texture *_texture, const SDL_Rect &_rect);

  int draw(SDL_Renderer *renderer, const SDL_Rect *dstrect) const;
  int draw(SDL_Renderer *renderer, const SDL_Rect *dstrect, double angle,
           const SDL_Point *center, SDL_RendererFlip flip) const;
  int draw(SDL_Renderer* renderer, int x, int y) const ;

  int draw(SDL_Renderer* renderer, int x, int y, SDL_RendererFlip flip) const;
  int getWidth() const { return rect.w; }

  int getHeight() const { return rect.h; }
};
#endif // TEXTURE_REGION_H
