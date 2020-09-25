#include "imagesize.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <exception>
#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

IImageSize::IImageSize(std::string name) : name(name) {}

ImageSizeCalculator::ImageSizeCalculator(std::string name) : IImageSize(name) {}

ImageSizeProxy::ImageSizeProxy(std::string name) : IImageSize(name)
{
    calc = new ImageSizeCalculator(name);
}

ImageSizeProxy::ImageSizeProxy(const ImageSizeProxy &isp) : IImageSize(isp.name)
{
    calc = new ImageSizeCalculator(name);
}

ImageSizeProxy::~ImageSizeProxy()
{
    delete calc;
}

int ImageSizeCalculator::getHeight() const
{
    sf::Texture texture;
    if(!texture.loadFromFile(name))
        throw std::exception();

    return texture.getSize().x;
}


int ImageSizeCalculator::getWight() const
{
    sf::Texture texture;
    if(!texture.loadFromFile(name))
        throw std::exception();

    return texture.getSize().y;
}

bool parser(std::string str, int &a, int &b)
{
    std::string delimetr = "/";
    std::string token;
    size_t pos = 0;
    while((pos = str.find(delimetr)) != std::string::npos)
    {
        token = str.substr(0, pos);
        str.erase(0, pos + delimetr.length());
    }   

    std::istringstream ss(str);
    char x = '0';
    while(ss)
    {
        if(x == '_') 
            break;
        ss >> x;
    }
    if(!ss)
    {
        return false;
    }
    ss >> a;
    ss >> x;
    ss >> b;

    return x == 'x';
}


int ImageSizeProxy::getHeight() const
{
    int height, weight;
    if(!parser(name, height, weight))
    {
        height = calc->getHeight();
    }
    return height;
}


int ImageSizeProxy::getWight() const
{
    int height, weight;
    if(!parser(name, height, weight))
    {
        weight = calc->getWight();
    }


    return weight;
}


