#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

/*
    Splice represents two images spliced together in some way.

    the left one is the one manipulated.
*/
class Splice
{
    public:
        Splice(const sf::Image*,const sf::Image*);

        const sf::Image * getRightImage();
        const sf::Image * getLeftImage();

        void setColorToReplace(sf::Color);

        sf::Image createSplicedImage();
    private:
        const sf::Image * leftImage;
        const sf::Image * rightImage;
        sf::Color switchColor;

};