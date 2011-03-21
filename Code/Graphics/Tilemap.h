#pragma once

#include "../Graphics.h"
#include "../Tileset.h"
#include "../TextureAsset.h"
#include "../Vector2.h"
#include <vector>

namespace Monocle
{
class Tilemap : public Graphic
{
	public:
		Tilemap(Tileset *tileset, int width, int height, int tileWidth, int tileHeight);

		void Resize(int width, int height);

		void GetWidthHeight(int *width, int *height);

		bool IsTile(int tx, int ty, int tileID);
		int GetTile(int tx, int ty);
		void SetTile(int tx, int ty, int tileID);

		int GetTileAtWorldPosition(const Vector2 &position);
		void SetTileAtWorldPosition(const Vector2 &position, int tileID);

		void WorldToTile(const Vector2 &position, int *tx, int *ty);

		void Update();
		void Render();

		TextureAsset *texture;

	private:
		Tileset *tileset;
		int width, height;
		int tileWidth, tileHeight;
		std::vector<int> tiles;
	};
}