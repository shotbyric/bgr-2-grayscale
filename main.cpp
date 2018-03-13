#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


int main() {
    
    char charCheckForEscKey = 0; // char stores value of key pressed from keyboard
    bool iscolor = true; // variable used as flag to determine if color image is being displayed
    
    /* Read Image */
    cv::Mat image1 = cv::imread("/Users/........../test image.jpg"); 

    if(image1.empty()){                                         // chack if image was properly read
        std::cout << "Unable to read image / Image not found" << std::endl;
        return 9;
    }
    
    cv::resize(image1, image1, cv::Size(image1.cols/4, image1.rows/4)); // resize to fit in my screen
    
    cv::Mat image2;
    cv::cvtColor(image1, image2, CV_BGR2GRAY);                  // store a black and white copy of image1 into image2
    
    cv::namedWindow("Black and White Image", CV_WINDOW_NORMAL); // set up window where B&W image will be shown
    cv::namedWindow("Color Image", CV_WINDOW_NORMAL);           // set up window where color image will be shown
  
    cv::imshow("Color Image", image1);                          // show color image initially
    

    while (1) {
        if(charCheckForEscKey == 27){ break;}                   // exit while loop if 'esc' key is pressed
        
        if((charCheckForEscKey == 'g') && (iscolor == true)){   // change to B&W image if 'g' is pressed on keyboard
            cv::destroyWindow("Color Image");
            cv::imshow("Black and White Image", image2);
            iscolor = false;
        }
        
        else if((charCheckForEscKey == 'c') && (iscolor == false)){
            cv::destroyWindow("Black and White Image");         // change to color image if 'c' is pressed on keyboard
            cv::imshow("Color Image", image1);
            iscolor = true;
        }
        
        charCheckForEscKey = cv::waitKey(20);                   // check if a key from keyboard has been pressed
        
    }
    
    return 0;
}
