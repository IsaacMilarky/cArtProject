#pragma once
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

/*
    Splice represents two images spliced together in some way.

    the left one is the one manipulated.
*/
class Splice
{
    public:
        Splice(const cv::Mat*,const cv::Mat*);

        const cv::Mat * getRightImage();
        const cv::Mat * getLeftImage();

        void setColorToReplace(cv::Vec3b);

        cv::Mat createSplicedImage();
    private:
        bool colorsAreEqual(cv::Vec3b, cv::Vec3b);

        const cv::Mat * leftImage;
        const cv::Mat * rightImage;
        cv::Vec3b switchColor;

};