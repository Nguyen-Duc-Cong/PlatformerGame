#ifndef TILESETS_H
#define TILESETS_H
#include "SDL_render.h"
#include "Tileset.h"
#include "tmxlite/Tileset.hpp"
class Tile;
class Tilesets
{
  public:
    Tilesets(const std::vector<tmx::Tileset>& tilesets, SDL_Renderer* renderer);
    ~Tilesets();

    Tile* GetTile(int tileID) const;
    bool  HasTile(int tileID) const;

  private:
    Tileset** m_items;
    int       m_numTilesets;
};
#endif // TILESETS_H
