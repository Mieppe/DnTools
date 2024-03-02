#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "utils.hpp"
#include "image.hpp"
#include <opencv2/opencv.hpp>

int main(int argc, char const *argv[])
{
    std::cout<<"Hello World !!"<<std::endl;

    PixelMatrix matrix = PixelMatrix();
    std::cout<<matrix.isEmpty()<<std::endl;
    matrix.setSizeHeight(3);
    std::cout<<matrix.isEmpty()<<std::endl;
    matrix.setSizeWidth(3);
    std::cout<<matrix.isEmpty()<<std::endl;
    Image img = Image(matrix, 10);
    cv::Mat generatedImage = img.generateCVImage();
    char window[] = "pixel art";
    cv::imshow(window, generatedImage);
    cv::waitKey(0);
    return 0;
}
