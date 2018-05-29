#pragma once

#include "Object.h"
#include "Player.h"
#include <SFML\Graphics.hpp>

class Platform : public Object
{
public:
	Platform();
	Platform(int xPos, int yPos, int platformType, sf::Color color);
	int detectCollision(Player &play);
	int detectCollisionTop(Player &play);
	int detectCollisionBottom(Player &play);
	void movingPlatform();

	bool hurtPlayer(Player &play);

	~Platform();
protected:
	sf::Vector2f center;
	int m_platformType;
	float m_time = 0.0f;
};

