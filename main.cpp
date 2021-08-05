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
	if(argc != 3)
		return -1;

    std::string leftImageFileName = argv[1];
	std::string rightImageFileName = argv[2];

	sf::Image * leftImage = new sf::Image;

	sf::Image * rightImage = new sf::Image;
	
	//Try to load image from filepath
	//Later this path should take a user input.
	if(!leftImage->loadFromFile(leftImageFileName))
	{
		std::cout << "File path is incorrect or error loading image." << std::endl;
		std::cin.get();

		delete leftImage;
		delete rightImage;
		return -1;
	}


	if(!rightImage->loadFromFile(rightImageFileName))
	{
		std::cout << "error" << std::endl;

		delete leftImage;
		delete rightImage;
		return -1;
	}
	std::cout << "Load successful" << std::endl;

	Splice product = Splice(leftImage, rightImage);
	product.setColorToReplace(sf::Color(0,0,0));

	std::cout << "Splicing..." << std::endl;
	sf::Image finalImage = product.createSplicedImage();
	finalImage.saveToFile("Art.jpg");

	delete leftImage;
	delete rightImage;
	return 0;
}

bool isUniqueColor(sf::Color claim, std::vector<sf::Color> * listCheck)
{
	for(unsigned i = 0; i < listCheck->size(); ++i)
		if(listCheck->at(i) == claim)
			return false;
	return true;
}
