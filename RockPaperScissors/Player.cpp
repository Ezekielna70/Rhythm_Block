#include "Player.h"
#include <sstream>
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed): 
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = 1;

	body.setSize(sf::Vector2f(100.f, 100.f));
	body.setPosition(640.0f, 440.0f);
	body.setTexture(texture);
	score = 0;
}
int Player::tampilScore()
{
	return score;
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;
	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;

		if (movement.x > 0.0f)
		{
			faceRight = 1;
		}
		else
			faceRight = 0;
	}
	
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
	

	
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

sf::Vector2f Player::getSize()
{
	return body.getSize();
}

sf::Vector2f Player::getPosisi()
{
	return body.getPosition();
}
