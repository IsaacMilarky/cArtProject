#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <opencv2/opencv.hpp>
#include "splice.hpp"


//bool isUniqueColor(sf::Color,std::vector<sf::Color>*);
cv::Vec3b findAverageColor(cv::Mat *);

int main(int argc, char *argv[])
{
	std::srand(std::time(0));

	std::cout << "You have entered" << argc << " arguments:" << "\n";
	if(argc != 3)
		return -1;

  
  	std::string leftImageFileName = argv[1];
	std::string rightImageFileName = argv[2];

	cv::Mat leftImage = cv::imread(leftImageFileName, 1);

	cv::Mat rightImage = cv::imread(rightImageFileName, 1);
	
	//Try to load image from filepath
	//Later this path should take a user input.
	if(!leftImage.data)
	{
		std::cout << "File path is incorrect or error loading image." << std::endl;
		std::cin.get();

		return -1;
	}


	if(!rightImage.data)
	{
		std::cout << "error" << std::endl;

		return -1;
	}
	std::cout << "Load successful" << std::endl;

	Splice product = Splice(&leftImage, &rightImage);
	product.setColorToReplace(findAverageColor(&leftImage));

	std::cout << "Splicing..." << std::endl;
	auto finalImage = product.createSplicedImage();

	imwrite("Product.jpg", finalImage);
  
	return 0;
}

/*
bool isUniqueColor(sf::Color claim, std::vector<sf::Color> * listCheck)
{
	for(unsigned i = 0; i < listCheck->size(); ++i)
		if(listCheck->at(i) == claim)
			return false;
	return true;
}
*/

cv::Vec3b findAverageColor(cv::Mat * image)
{
	//Reserve stack variables
	long double averageB = 0;
	long double averageG = 0;
	long double averageR = 0;

	//Get total amount of pixels
	cv::Size imageDimensions = image->size();

	unsigned long totalPixels = imageDimensions.width * imageDimensions.height;

	//Get average of each pixel
	for(int x = 0; x < imageDimensions.width; ++x)
	{
		for(int y = 0; y < imageDimensions.height; ++y)
		{
			//Get pixel
			cv::Vec3b pixel = image->at<cv::Vec3b>(cv::Point(x,y));

			//Updating averages
			averageB += pixel.val[0] ;/// totalPixels;
			averageG += pixel.val[1] ;/// totalPixels;
			averageR += pixel.val[2] ;/// totalPixels;

			std::cout << averageB << std::endl;
		}
	}

	return cv::Vec3b(averageB / totalPixels,averageG / totalPixels, averageR / totalPixels);
}