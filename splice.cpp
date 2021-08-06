#include "splice.hpp"


Splice::Splice(const sf::Image * left, const sf::Image * right)
{
    this->leftImage = left;
    this->rightImage = right;
    //std::cout << this->leftImage->getSize().x << std::endl;
}

const sf::Image * Splice::getRightImage()
{
    return this->rightImage;
}

const sf::Image * Splice::getLeftImage()
{
    return this->leftImage;
}

void Splice::setColorToReplace(sf::Color toReplace)
{
    this->switchColor = toReplace;
}

sf::Image Splice::createSplicedImage()
{
    sf::Image toReturn = sf::Image();
    //std::cout << this->leftImage << std::endl;
    //Make empty image the same size as the left image.
    toReturn.create(this->leftImage->getSize().x,this->leftImage->getSize().y, NULL);

    
    for(unsigned x = 0; x < this->leftImage->getSize().x; ++x)
    {
        for(unsigned y = 0; y < this->leftImage->getSize().y; ++y)
        {
            //Use a modulus to keep it in range.
            if(this->leftImage->getPixel(x,y) == this->switchColor)
                toReturn.setPixel(x,y,this->rightImage->getPixel(x % this->rightImage->getSize().x,y % this->rightImage->getSize().y));
        }
        std::cout << x << std::endl;
    }

    return toReturn;
}