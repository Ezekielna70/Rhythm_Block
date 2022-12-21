#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include <iostream>

class buah
{
public:
	buah(float x, float y);
	void update(float deltaTime, Player* pemain);
	void render(sf::RenderWindow* mWindow);

	void jatuh();
	void setPosisi(sf::Vector2f posisi);

	void isCollision(Player* pemain);

	int getPoints();

	bool is_collision;

private:
	
	sf::RectangleShape mBola;
	sf::Vector2f gravity;
};

