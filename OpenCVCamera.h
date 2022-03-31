#pragma once
/**
 * @file OpenCVCamera.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date $DATE
 * 
 * @copyright Copyright (c) 2022
 */


#include <opencv2/opencv.hpp>
/**
 * @brief 
 * 
 */
struct OpenCVCamera {
    

    std::shared_ptr<cv::VideoCapture> capture_;
    
    /**
     * @brief Construct a new OpenCVCamera object
     * 
     */
    OpenCVCamera() {}
};
