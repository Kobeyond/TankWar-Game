#include "TileMap.h"
#include <SFML/Graphics.hpp>


void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	states.transform *= getTransform();
	states.texture = &texture_tileset;
	target.draw(m_vertices, states);

}

/*�øú���load������ͼ��ֻ��Ҫһ����Ƭͼ����������Ƭ�ĳߴ磬
��ͼ����Ƭ�����ϵĿ�Ⱥ͸߶ȣ��Լ�����Ϊ������ͼ�Ķ�λ����tileArray*/
bool TileMap::load(const std::string& fileName, sf::Vector2u tileSize, int *tileArray, unsigned int width, unsigned int height) {

	if (!texture_tileset.loadFromFile("E:\\VS Files\\SFML_Programming\\tileset.png")) {
		return false;
	}
	
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width*height * 4);

	for (unsigned int i = 0; i < width; i++) {    //��������(i,j)������Ƭ
		for (unsigned int j = 0; j < height; j++) {

			int tileNumber = tileArray[i + j*width];  //��ͬ����ֵ����ͬ�ĺ��壬��ǽ������������


			/*�ҵ���Ӧλ����Ƭͼ���е����꣬��Ϊ��Ƭ�������Ǿ��ε�*/
			int tu = tileNumber % (texture_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (texture_tileset.getSize().x / tileSize.x);

			sf::Vertex* quad = &m_vertices[(i + j*width) * 4];


			/*��ÿ����Ƭ���ĸ�������Ļ�ϵ�λ��ȷ������*/
			quad[0].position = sf::Vector2f(i*tileSize.x, j*tileSize.y);
			quad[1].position = sf::Vector2f((i + 1)*tileSize.x, j*tileSize.y);
			quad[2].position = sf::Vector2f((i + 1)*tileSize.x, (j + 1)*tileSize.y);
			quad[3].position = sf::Vector2f(i*tileSize.x, (j + 1)*tileSize.y);


			/*��ÿ����Ƭ����Ƭͼ���Ͽٳ���Ӧ������*/
			quad[0].texCoords = sf::Vector2f(tu*tileSize.x, tv*tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1)*tileSize.x, tv*tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1)*tileSize.x, (tv + 1)*tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu*tileSize.x, (tv + 1)*tileSize.y);
		}
	}

	return true;
}