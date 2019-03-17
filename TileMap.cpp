#include "TileMap.h"
#include <SFML/Graphics.hpp>


void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	states.transform *= getTransform();
	states.texture = &texture_tileset;
	target.draw(m_vertices, states);

}

/*用该函数load整个地图，只需要一个瓦片图集，生成瓦片的尺寸，
地图的瓦片数量上的宽度和高度，以及抽象为整个地图的二位数组tileArray*/
bool TileMap::load(const std::string& fileName, sf::Vector2u tileSize, int *tileArray, unsigned int width, unsigned int height) {

	if (!texture_tileset.loadFromFile("E:\\VS Files\\SFML_Programming\\tileset.png")) {
		return false;
	}
	
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width*height * 4);

	for (unsigned int i = 0; i < width; i++) {    //操作处于(i,j)处的瓦片
		for (unsigned int j = 0; j < height; j++) {

			int tileNumber = tileArray[i + j*width];  //不同的数值代表不同的含义，如墙、树、河流等


			/*找到对应位于瓦片图集中的坐标，因为瓦片集可能是矩形的*/
			int tu = tileNumber % (texture_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (texture_tileset.getSize().x / tileSize.x);

			sf::Vertex* quad = &m_vertices[(i + j*width) * 4];


			/*把每个瓦片的四个角在屏幕上的位置确定下来*/
			quad[0].position = sf::Vector2f(i*tileSize.x, j*tileSize.y);
			quad[1].position = sf::Vector2f((i + 1)*tileSize.x, j*tileSize.y);
			quad[2].position = sf::Vector2f((i + 1)*tileSize.x, (j + 1)*tileSize.y);
			quad[3].position = sf::Vector2f(i*tileSize.x, (j + 1)*tileSize.y);


			/*把每个瓦片在瓦片图集上抠出对应的区域*/
			quad[0].texCoords = sf::Vector2f(tu*tileSize.x, tv*tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1)*tileSize.x, tv*tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1)*tileSize.x, (tv + 1)*tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu*tileSize.x, (tv + 1)*tileSize.y);
		}
	}

	return true;
}