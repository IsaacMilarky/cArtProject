#include "splice.hpp"


Splice::Splice(sf::Image left, sf::Image right)
{
    this->leftImage = leftImage;
    this->rightImage = rightImage;
}

const sf::Image * Splice::getRightImage()
{
    //Create constant reference to image to avoid useless copies
    const sf::Image * rightRef = &this->rightImage;
    return rightRef;
}

const sf::Image * Splice::getLeftImage()
{
    const sf::Image * leftRef = &this->leftImage;
    return leftRef;
}

void Splice::setColorToReplace(sf::Color toReplace)
{
    this->switchColor = toReplace;
}

sf::Image Splice::createSplicedImage()
{
    for(unsigned x = 0; x < this->leftImage.getSize().x; ++x)
    {
        for(unsigned y = 0; y < this->leftImage.getSize().y; ++y)
        {
            if(this->leftImage.getPixel(x,y) == this->switchColor)
                this->leftImage.setPixel(x,y,this->rightImage.getPixel(x,y));
        }
        std::cout << (double)(x/this->leftImage.getSize().x) * 100. << '%' << std::endl;
    }
}