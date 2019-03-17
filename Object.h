#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::Sprite {

private:
	int speed;

public:
	void setObstacleSpeed(int sp) { speed = sp; }
	int getObstacleSpeed() { return speed; }
	
public:
	/*�ж��Ƿ��ߵ��߽�*/
	bool ifLeftBoundary();
	bool ifRightBoundary();
	bool ifUpBoundary();
	bool ifDownBoundary();
	
public:
	/*�ж�ǰ��һ��ǽ�Ľӽ��̶�*/
	int ifLeftReach();
	int ifRightReach();
	int ifUpReach();
	int ifDownReach();

public:
	/*�жϵ���ǽʱǰ���Ƿ����ϰ���*/
	bool ifLeftObstacle();
	bool ifRightObstacle();
	bool ifUpObstacle();
	bool ifDownObstacle();

};




