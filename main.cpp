#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

bool isUniqueColor(sf::Color,std::vector<sf::Color>*);

int main()
{
	std::srand(std::time(0));

    const std::string filepath = "ufofgaa45ya41.jpg";
	sf::Image toManip;

	sf::Image face;
	
	//Try to load image from filepath
	//Later this path should take a user input.
	if(!toManip.loadFromFile(filepath))
	{
		std::cout << "File path is incorrect or error loading image." << std::endl;
		std::cin.get();
		return -1;
	}
	if(!face.loadFromFile("face.jpeg"))
	{
		std::cout << "cunt" << std::endl;
		return -1;
	}
	std::cout << "Load successful" << std::endl;

	for(unsigned x = 0; x < toManip.getSize().x; ++x)
	{
		for(unsigned y = 0; y < toManip.getSize().y; ++y)
		{
			if(toManip.getPixel(x,y) == sf::Color(0,0,0))
				toManip.setPixel(x,y,face.getPixel(x,y));
			
		}
		//the things i do for cunt shit fuck cunt
		std::cout << (double)(x/toManip.getSize().x) * 100. << '%' << std::endl;
	}
	return 0;
}

bool isUniqueColor(sf::Color claim, std::vector<sf::Color> * listCheck)
{
	for(unsigned i = 0; i < listCheck->size(); ++i)
		if(listCheck->at(i) == claim)
			return false;
	return true;
}
