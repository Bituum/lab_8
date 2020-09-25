#include "imagesize.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

int main(const int argc, const char **argv)
{
    if(argc != 2)
    {
        return 1;
    }
    

    std::string filename(argv[1]);
    IImageSize *isize = new ImageSizeProxy(filename);

    int height = isize->getHeight();
    int weight = isize->getWight();
    
    std::cout << height << " " << weight;


    sf::RenderWindow window(sf::VideoMode(isize->getHeight(), isize->getWight()), "\nSFML WORKS!\n");
    sf::Texture texture;
    sf::Sprite sprite;

    sprite.setTextureRect(sf::IntRect(0, 0, height, weight));

    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
            window.close();
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
        }
        delete isize;

    return 0;
}
