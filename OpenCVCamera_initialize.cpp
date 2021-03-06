#include <juiz/juiz.h>
#include <juiz/container.h>

#include "OpenCVCamera.h"

using namespace juiz;


extern "C" {

    JUIZ_OPERATION  void* OpenCVCamera_initialize() {
        return containerOperationFactory<OpenCVCamera>(
            {
              {"typeName", "initialize"},
              {"defaultArg", {
                {"cameraId", 0},
                {"width", 320},
                {"height", 240}
              }},
            },
            [](auto& container, auto arg) -> juiz::Value {
                //std::cout << "OpenCVCamera_initialize (arg:" << str(arg) << std::endl;
                container.capture_ = std::make_shared<cv::VideoCapture>(arg.at("cameraId").intValue());
                container.capture_->set(cv::CAP_PROP_FRAME_WIDTH, arg.at("width").intValue());
                container.capture_->set(cv::CAP_PROP_FRAME_HEIGHT, arg.at("height").intValue());
                //container.gamepad = std::make_shared<ssr::aqua2::GamePad>(arg.at("arg").stringValue().c_str());
                return arg;
            }
        );
    }

}
