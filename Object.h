#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::Sprite {

private:
	int speed;

public:
	void setObstacleSpeed(int sp) { speed = sp; }
	int getObstacleSpeed() { return speed; }
	
public:
	/*判断是否走到边界*/
	bool ifLeftBoundary();
	bool ifRightBoundary();
	bool ifUpBoundary();
	bool ifDownBoundary();
	
public:
	/*判断前方一个墙的接近程度*/
	int ifLeftReach();
	int ifRightReach();
	int ifUpReach();
	int ifDownReach();

public:
	/*判断当贴墙时前面是否有障碍物*/
	bool ifLeftObstacle();
	bool ifRightObstacle();
	bool ifUpObstacle();
	bool ifDownObstacle();

};




