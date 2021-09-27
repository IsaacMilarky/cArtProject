#include "splice.hpp"


Splice::Splice(const cv::Mat * left, const cv::Mat * right)
{
    this->leftImage = left;
    this->rightImage = right;
    //std::cout << this->leftImage->getSize().x << std::endl;
}

const cv::Mat * Splice::getRightImage()
{
    return this->rightImage;
}

const cv::Mat * Splice::getLeftImage()
{
    return this->leftImage;
}

void Splice::setColorToReplace(cv::Vec3b toReplace)
{
    this->switchColor = toReplace;
}

cv::Mat Splice::createSplicedImage()
{

    cv::Size leftSize = this->leftImage->size();
    cv::Size rightSize = this->rightImage->size();
    cv::Mat toReturn = cv::Mat(leftSize.width, leftSize.height, CV_8UC3, cv::Scalar(0,0,0));
    //std::cout << this->leftImage << std::endl;
    //Make empty image the same size as the left image.
    
    for(int x = 0; x < leftSize.width; ++x)
    {
        for(int y = 0; y < leftSize.height; ++y)
        {

            //Get pixel
            cv::Vec3b pixel = this->leftImage->at<cv::Vec3b>(cv::Point(x,y));
            //Use a modulus to keep it in range.
            if(this->colorsAreEqual(pixel,this->switchColor))
            {
              //auto color = this->rightImage->getPixel(x % this->rightImage->getSize().x,y % this->rightImage->getSize().y);
            

              auto color = this->rightImage->at<cv::Vec3b>(cv::Point(x % rightSize.width,y % rightSize.height));

              toReturn.at<cv::Vec3b>(x,y) = color;
              std::cout << "(x,y): (" << x << "," << y << ") " << std::endl;
            }
                
        }
        //std::cout << x << std::endl;
    }

    cv::imshow("Example", toReturn);
    return toReturn;
}


bool Splice::colorsAreEqual(cv::Vec3b colorOne, cv::Vec3b colorTwo)
{
    return colorOne.val[0] == colorTwo.val[0] && colorOne.val[1] == colorTwo.val[1] && colorOne.val[2] == colorTwo.val[2];
}