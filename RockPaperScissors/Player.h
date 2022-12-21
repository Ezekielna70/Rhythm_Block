#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Animation.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	int tampilScore();

	sf::Vector2f getSize();
	sf::Vector2f getPosisi();
	int score;
	


private:
	
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};
