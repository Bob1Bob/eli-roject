#include "Platform.h"



Platform::Platform()
{
}

Platform::Platform(int xPos, int yPos, int platformType, sf::Color color)
{
	if (platformType != 9) {
		m_xPos = xPos * 100.0f;
		m_yPos = yPos * 100.0f;
		m_width = 100.0f;
		m_height = 100.0f;
	}
	else if (platformType == 9) {
		m_xPos = xPos * 100.0f + 25.0f;
		m_yPos = yPos * 100.0f + 25.0f;
		m_width = 50.0f;
		m_height = 50.0f;
	}
	m_platformType = platformType;
	obj.setFillColor(color);
	obj.setSize(sf::Vector2f(m_width, m_height));
	obj.setPosition(sf::Vector2f(m_xPos, m_yPos)); // sets position of platform
}

int Platform::detectCollision(Player &play)
{
	
	sf::Vector2f objectCenter((float)m_xPos + (getWidth() / 2), (float)m_yPos + 50.0f);
	if (m_yPos + (getHeight() / 2) >= play.getYValue() + (play.getHeight() / 2)){
		if ((m_xPos + (getWidth() / 2)) >= play.getXValue() + (play.getWidth() / 2)) {
			if ((m_xPos + (getWidth() / 2)) - (play.getXValue() + (play.getWidth() / 2)) < play.getWidth() / 2 + m_width / 2 && (m_yPos + (getHeight() / 2)) - (play.getYValue() + (play.getHeight() / 2)) < play.getHeight() / 2 + m_height / 2 && play.m_movingPlatform == false) {
				if (m_platformType != 9 && m_platformType != 90){
					play.collideRight();
				}
				else if (m_platformType != 90) {
					m_platformType = 90;
					play.m_coins += 1;
					play.m_totalCoins += 1;
					obj.setFillColor(sf::Color::Transparent);
					obj.setPosition(sf::Vector2f(-1000.0f, -1000.0f));
				}
				if (m_platformType == 100 && play.m_isPlayer == false) {
					play.setColor(sf::Color::Transparent);
				}

				//std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
				return 1;
			}
			else {
				return 0;
			}
		}
		else {

			if (((play.getXValue() + (play.getWidth() / 2)) - (m_xPos + (getWidth() / 2))) < play.getWidth() / 2 + m_width / 2 && (m_yPos + (getHeight() / 2)) - (play.getYValue() + (play.getHeight() / 2)) <  play.getHeight() / 2 + m_height / 2 && play.m_movingPlatform == false) {
				if (m_platformType != 9 && m_platformType !=90) {
					play.collideLeft();
				}
				else if (m_platformType != 90) {
					m_platformType = 90;
					play.m_coins += 1;
					play.m_totalCoins += 1;
					obj.setFillColor(sf::Color::Transparent);
					obj.setPosition(sf::Vector2f(-1000.0f, -1000.0f));
				}
				//std::cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
				if (m_platformType == 100 && play.m_isPlayer == false) {
					play.setColor(sf::Color::Transparent);
				}
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	else {
		return 0;
	}

}

int Platform::detectCollisionTop(Player & play)
{
	if (play.getYValue() + (play.getHeight() / 2) >= m_yPos - (getHeight() / 2)) {
		//if ((obj.getPosition().x + 50.0f) - (play.getXValue() + 50.0f) <= m_width && (obj.getPosition().y + 50.0f) - (play.getYValue() + 50.0f) <= m_height && ((obj.getPosition().x + 50.0f) - (play.getXValue() + 50.0f) >= m_width)) {
		//	return true;
		//}
		if ((((play.getXValue() + (play.getWidth() / 2)) - (m_xPos + (getWidth() / 2))) < play.getWidth() / 2 + m_width / 2 && (play.getYValue() + (play.getHeight() / 2)) - (m_yPos + (getHeight() / 2)) < play.getHeight() / 2 + m_height / 2) && ((m_xPos + (getWidth() / 2)) - (play.getXValue() + (play.getWidth() / 2)) < play.getWidth() / 2 + m_width / 2)) {
			if (m_platformType == 3) {
				play.updateXPos(sin(m_time * 0.5));
				return 1;
			}
			if (m_platformType == 4) {
				play.updateYPos(-sin(m_time * 0.5) );
				return 2;
			}
			if (m_platformType == 9) {
				m_platformType = 90;
				play.m_coins += 1;
				play.m_totalCoins += 1;
				obj.setFillColor(sf::Color::Transparent);
				obj.setPosition(sf::Vector2f(-1000.0f, -1000.0f));
				return 0;
			}
			if (m_platformType == 90) {
				return 0;
			}
			if (m_platformType == 10) {
				return 100;
			}
			//ending platform

			//bullet
			if (m_platformType == 100 && play.m_isPlayer == false) {
				play.setColor(sf::Color::Transparent);
			}
			else
				return 1;
		}
		else {
			return 0;
		}
	}
	else
		return 0;
}

int Platform::detectCollisionBottom(Player & play)
{
	if (m_yPos - (getHeight() / 2) >= play.getYValue() - (play.getWidth() / 2)) {
		//if ((((play.getXValue() + (play.getWidth() / 2)) - (m_xPos + (getWidth() / 2))) < play.getWidth() / 2 + m_width / 2 && -(play.getYValue() + (play.getHeight() / 2)) + (m_yPos + (getHeight() / 2)) < play.getHeight() / 2 - m_height / 2) && ((m_xPos + (getWidth() / 2)) - (play.getXValue() + (play.getWidth() / 2)) < play.getWidth() / 2 + m_width / 2)) {
		//	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
		//	return 1;
	//	}

		if (((play.getXValue() + (play.getWidth() / 2)) - (m_xPos + (getWidth() / 2))) < play.getWidth() / 2 + m_width / 2 && (-(play.getYValue() + (play.getHeight() / 2)) + (m_yPos + (getHeight() / 2)) < play.getHeight() / 2 + m_height / 2) && ((m_xPos + (getWidth() / 2)) - (play.getXValue() + (play.getWidth() / 2)) < play.getWidth() / 2 + m_width / 2)) {
			//std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
			
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

void Platform::movingPlatform()
{

	if (m_platformType == 3) {
		//Player platform(m_xPos, m_yPos, m_width);
		float speed = 0.5f;
		if (m_time <= 720.0f) {
			m_time += 0.01f;
			m_xPos += sin(m_time * speed);
		}
		else {
			m_time = 0.0f;
			//m_xPos -= sin(m_time * speed);
		}
		
		obj.setPosition(sf::Vector2f(m_xPos, m_yPos));
		
	}
	else if (m_platformType == 4) {
		//Player platform(m_xPos, m_yPos, m_width);
		float speed = 0.5f;
		if (m_time <= 720.0f) {
			m_time += 0.01f;
			m_yPos -= sin(m_time * speed);
		}
		else {
			m_time = 0.0f;
			//m_xPos -= sin(m_time * speed);
		}

		obj.setPosition(sf::Vector2f(m_xPos, m_yPos));
	}
}

bool Platform::hurtPlayer(Player &play)
{
	if (m_platformType == 2) {
		if (detectCollision(play) == true || detectCollisionTop(play) == true) {
			play.loseHealth(0.1f);
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

Platform::~Platform()
{
}

