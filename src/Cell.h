#ifndef CELL_H
#define CELL_H
#include "NTTileLayerCell.h"
#include "Tile.h"
class Cell : public TileLayerCell
{
  public:
    bool isSoild() { return ((Tile*)getTile())->isSolid(); }
};
#endif // CELL_H
