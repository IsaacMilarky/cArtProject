#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "splice.hpp"


bool isUniqueColor(sf::Color,std::vector<sf::Color>*);

int main(int argc, char *argv[])
{
	std::srand(std::time(0));

	std::cout << "You have entered" << argc << " arguments:" << "\n";
    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << "\n";

    std::string leftImageFileName = argv[0];
	std::string rightImageFileName = argv[1];

	sf::Image leftImage;

	sf::Image rightImage;
	
	//Try to load image from filepath
	//Later this path should take a user input.
	if(!leftImage.loadFromFile(leftImageFileName))
	{
		std::cout << "File path is incorrect or error loading image." << std::endl;
		std::cin.get();
		return -1;
	}


	if(!rightImage.loadFromFile(rightImageFileName))
	{
		std::cout << "error" << std::endl;
		return -1;
	}
	std::cout << "Load successful" << std::endl;

	Splice product = Splice(leftImage, rightImage);
	product.setColorToReplace(sf::Color(0,0,0));

	sf::Image finalImage = product.createSplicedImage();
	finalImage.saveToFile("Art.jpg");

	return 0;
}

bool isUniqueColor(sf::Color claim, std::vector<sf::Color> * listCheck)
{
	for(unsigned i = 0; i < listCheck->size(); ++i)
		if(listCheck->at(i) == claim)
			return false;
	return true;
}
