#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>


#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "Player.h"
#include "buah.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Rick Rolled!");
    window.setFramerateLimit(60);
    sf::Texture texture0;
    if (!texture0.loadFromFile("Sprite/Moon.png"))
    {
        std::cout << "Error" << std::endl;
    }


    sf::Texture playerTexture;
    playerTexture.loadFromFile("Sprite/flatboy.png");


    Player player(&playerTexture, sf::Vector2u(15 , 2), 0.3f, 300.0f);

    float deltaTime = 0.0f;
    sf::Clock clock;

    sf::Sprite sprite(texture0);
    sprite.setTextureRect(sf::IntRect(0, 0, 1280, 720));

    sf::Music music;
    if (!music.openFromFile("Audio/music.ogg"))
        return -1; // error
    music.play();
    music.setLoop(true);

    //ini mengurus buah
    sf::Clock waktuJatuh;
    sf::Time elapsedTime;
    std::vector<buah> mBuah;
    buah Buah(640,20);
    int location = 640;
    bool kanan;
    int g;
    srand(time(0));

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        //mengurus buah
        
        elapsedTime = waktuJatuh.getElapsedTime();
        if (location <= 140)
        {
            location += 40;
        }
        else if (location >= 1140)
        {
            location -= 40;
        }
        else
        {
            g = std::rand();
            kanan = g % 2;
            if (kanan)
            {
                location +=10;
            }
            else 
                location -= 10;
        }
        if (elapsedTime.asSeconds() >= 1.88 ) {
            buah bhs(location, 20);
            mBuah.push_back(bhs);
            waktuJatuh.restart();
            std::cout << elapsedTime.asSeconds() << std::endl;
        }

        Buah.update(deltaTime,&player);
        for (int i = 0; i < mBuah.size(); i++) {
            mBuah[i].update(deltaTime, &player);
        }
        player.Update(deltaTime);


        window.draw(sprite);
        player.Draw(window);
        Buah.render(&window);
        for (int i = 0; i < mBuah.size(); i++) {
            mBuah[i].render(&window);
        }

        window.display();
    }
    return 0;
}


