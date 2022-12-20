#include "buah.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
int n;
int score;
bool touch;

buah::buah(float x, float y)
{
	srand(time(0));
	int random = 1 + (rand() % 3);
	mBola.setSize(sf::Vector2f(64.f, 64.f));
	if(random == 0)
		mBola.setFillColor(sf::Color::Magenta);
	else if(random == 1)
		mBola.setFillColor(sf::Color::Blue);
	else if (random == 2)
		mBola.setFillColor(sf::Color::Red);
	else if (random == 3)
		mBola.setFillColor(sf::Color::Green);

	mBola.setPosition(sf::Vector2f(x, y));
}

void buah::update(float deltaTime, Player* pemain)
{
	jatuh();
	isCollision(pemain);
	mBola.move(sf::Vector2f(0,gravity.y * deltaTime));

	if (mBola.getPosition().y >= 720) {
		gravity.y = 0;
	}
	if (is_collision && touch) {
		n++;
		score++;
		std::cout << n << std::endl;
		if (n > 5)
		{
			mBola.setFillColor(sf::Color::Transparent);
			n = 0;
		}
		
		
	}
}

void buah::render(sf::RenderWindow* mWindow)
{
	mWindow->draw(mBola);
}


void buah::jatuh()
{
	gravity.y += 10.f;
}

void buah::setPosisi(sf::Vector2f posisi)
{
	mBola.setPosition(posisi);
}

void buah::isCollision(Player* pemain)
{
	sf::Vector2f delta;
	sf::Vector2f jarak;

	delta.x = (mBola.getSize().x /2 + pemain->getSize().x / 2);
	delta.y = (mBola.getSize().y / 2 + pemain->getSize().y / 2);

	jarak.x = abs(mBola.getPosition().x - pemain->getPosisi().x);
	jarak.y = abs(mBola.getPosition().y - pemain->getPosisi().y);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		touch = 1;
	}
	else
	{
		touch = 0;
	}

	is_collision = false;
	if (jarak.x <= delta.x) {
		if ((jarak.y <= delta.y)&&touch) {
			is_collision = true;
		}
	}
}

void isMouse()
{
	
		

}
