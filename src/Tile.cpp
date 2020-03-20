#include "Tile.h"
#include "NTTileLayerAnimatedTile.h"
#include "NTTileLayerStaticTile.h"

Tile::Tile(const std::vector<NTTextureRegion>& staticTiles,
           const tmx::Tileset::Tile&           tileData)
{
    if (tileData.animation.frames.size() == 0)
    {
        m_tile = new NTTileLayerStaticTile(staticTiles[tileData.ID]);
    }
    else
    {
        std::size_t                  size = tileData.animation.frames.size();
        std::vector<NTTextureRegion> frames(size);
        std::vector<Uint32>          intervals(size);
        std::size_t                  index = 0;
        for (const auto& frame : tileData.animation.frames)
        {
            frames[index] = staticTiles[frame.tileID - 1];
            intervals[index] = frame.duration;
            ++index;
        }
        m_tile = new NTTileLayerAnimatedTile(frames, intervals);
    }
    for (const auto& property : tileData.properties)
    {
        if (property.getName() == "soild")
        {
            setSoild(property.getBoolValue());
        }
    }
}

Tile::~Tile() { delete m_tile; }
