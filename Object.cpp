#include "Object.h"
#include "Define.h"
#include "Map.h"


/*判断是否走到边界*/
bool Object::ifLeftBoundary() {	
	sf::Vector2f ObjectCenter = getPosition();
	if (ObjectCenter.x > getTextureRect().width/2) {
		return 0;
	}
	else return 1;
}

bool Object::ifRightBoundary() {
	sf::Vector2f ObjectCenter = getPosition();
	if (ObjectCenter.x < WindowWidth - getTextureRect().width/2) {
		return 0;
	}
	else return 1;
}

bool Object::ifUpBoundary() {
	sf::Vector2f ObjectCenter = getPosition();
	if (ObjectCenter.y > getTextureRect().height/2) {
		return 0;
	}
	else return 1;
}

bool Object::ifDownBoundary() {
	sf::Vector2f ObjectCenter = getPosition();
	if (ObjectCenter.y < WindowWidth - getTextureRect().height / 2) {
		return 0;
	}
	else return 1;
}



/*判断当贴墙时前面是否有障碍物*/
bool Object::ifLeftObstacle() {
	/*要能保证能往某个地方走，应该是tank前面两个角都不碰到障碍物！！！！！*/
	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	/*方向为左的时候左上角坐标*/
	FrontCorner1.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y + getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	/*方向为左的时候右上角坐标*/
	FrontCorner2.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y - getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;


	if (j1 == (double)FrontCorner1.y / WallSize   /*如果只占一格空间*/
		|| j2 == (double)FrontCorner2.y / WallSize
		|| j1 == j2) {
		tile1 = Map::tilesArray[i2 + j2*Width - 1];
		tile2 = tile1;
	}
	
	else {   /*如果占两格空间*/
		tile1 = Map::tilesArray[i1 + j1*Width - 1];
		tile2 = Map::tilesArray[i2 + j2*Width - 1];
	}

	if (tile1 != Water && tile1 != Tree && tile2 != Water && tile2 != Tree) {
		return 0;
	}
	else return 1;
		
}

bool Object::ifRightObstacle() {

	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	/*方向为右的时候左上角坐标*/
	FrontCorner1.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y - getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	/*方向为右的时候右上角坐标*/
	FrontCorner2.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y + getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;

	/*如果只占一格空间*/
	if (j1 == (double)FrontCorner1.y / WallSize
		|| j2 == (double)FrontCorner2.y / WallSize
		|| j1 == j2) {
		tile1 = Map::tilesArray[i1 + j1*Width];
		tile2 = tile1;
	}
	else {   	/*如果占两格空间*/
		tile1 = Map::tilesArray[i1 + j1*Width];
		tile2 = Map::tilesArray[i2 + j2*Width];
	}

	if (tile1 != Water && tile1 != Tree && tile2 != Water && tile2 != Tree) {
		return 0;
	}
	else return 1;
		
}

bool Object::ifUpObstacle() {  //仅仅用于判断当贴墙的时候，前方是否被堵住


	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	/*方向为上的时候左上角坐标*/
	FrontCorner1.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y - getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	/*方向为上的时候右上角坐标*/
	FrontCorner2.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y - getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;

	/*如果只占一格空间*/
	if (i1 == (double)FrontCorner1.x / WallSize
		|| i2 == (double)FrontCorner2.x / WallSize
		|| i1 == i2) {
		tile1 = Map::tilesArray[i1 + (j1 - 1)*Width];
		tile2 = tile1;
	}
	/*如果占两格空间*/
	else {
		tile1 = Map::tilesArray[i1 + (j1 - 1)*Width];
		tile2 = Map::tilesArray[i2 + (j2 - 1)*Width];
	}

	if (tile1 != Water && tile1 != Tree && tile2 != Water && tile2 != Tree) {
		return 0;
	}
	else {
		return 1;
	}
	
		
}

bool Object::ifDownObstacle() {

	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	/*方向为下的时候左上角坐标*/
	FrontCorner1.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y + getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	/*方向为下的时候右上角坐标*/
	FrontCorner2.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y + getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;

	 /*如果只占一格空间*/
	if (i1 == (double)FrontCorner1.x / WallSize
		|| i2 == (double)FrontCorner2.x / WallSize
		|| i1 == i2) {
		tile1 = Map::tilesArray[i2 + j2*Width];
		tile2 = tile1;
	}	
	else {  /*如果占两格空间*/
		tile1 = Map::tilesArray[i1 + j1*Width];
		tile2 = Map::tilesArray[i2 + j2*Width];
	}
	if (tile1 != Water && tile1 != Tree && tile2 != Water && tile2 != Tree) {
		return 0;
	}
	else {
		return 1;
	}	
}



/*判断前方一个墙的接近程度*/
int Object::ifLeftReach() {

	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	/*方向为左的时候左上角坐标*/
	FrontCorner1.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y + getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	/*方向为左的时候右上角坐标*/
	FrontCorner2.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y - getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;

	if (FrontCorner1.x - getObstacleSpeed() > i1*WallSize) {   /*安全距离外，以speed速度走*/
		return 0;
	}
	else if (FrontCorner1.x > i1*WallSize) {   /*安全距离内，一格一格走*/
		return 1;
	}
	else return 2;
}

int Object::ifRightReach() {

	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	/*方向为右的时候左上角坐标*/
	FrontCorner1.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y - getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	/*方向为右的时候右上角坐标*/
	FrontCorner2.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y + getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;


	if (FrontCorner1.x == i1*WallSize) {
		return 2;
	}
	else if (FrontCorner1.x + getObstacleSpeed() < (i1 + 1)*WallSize) {
		return 0;
	}
	else if (FrontCorner1.x < (i1 + 1)*WallSize) {
		return 1;
	}
	
	
}

int Object::ifUpReach() {  /*安全距离外返回0，安全距离内返回1，贴上返回2*/

	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	/*方向为上的时候左上角坐标*/
	FrontCorner1.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y - getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	/*方向为上的时候右上角坐标*/
	FrontCorner2.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y - getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;

	if (FrontCorner1.y - getObstacleSpeed() > j1*WallSize) {   /*安全距离外，以speed速度走*/
		return 0;
	}
	else if (FrontCorner1.y > j1*WallSize) {   /*安全距离内，一格一格走*/
		return 1;
	}
	else return 2;
}

int Object::ifDownReach() {

	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;


	/*方向为下的时候左上角坐标*/
	FrontCorner1.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y + getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	/*方向为下的时候右上角坐标*/
	FrontCorner2.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y + getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;

	if (FrontCorner1.y == j1*WallSize) {
		return 2;
	}
	else if (FrontCorner1.y + getObstacleSpeed() < (j1 + 1)*WallSize) {
		return 0;
	}
	else if (FrontCorner1.y < (j1 + 1)*WallSize) {
		return 1;
	}

}