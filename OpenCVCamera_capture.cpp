#include <juiz/juiz.h>
#include <juiz/container.h>

#include "OpenCVCamera.h"

using namespace juiz;


extern "C" {

    JUIZ_OPERATION  void* OpenCVCamera_capture() {
        return containerOperationFactory<OpenCVCamera>(
            {
              {"typeName", "capture"},
              {"defaultArg", {
                  {}
              }},
            },
            [](auto& container, auto arg) -> juiz::Value {
                logger::trace("OpenCVCamera_capture called");
                    if (container.capture_) {
                    cv::Mat frame;
                    if (!container.capture_->read(frame)) {
                        return Value::error("VideoCapture failed.");
                    }

                    // std::cout << "rows:" << frame.rows << ", cols:" << frame.cols << ", channels:" << frame.channels() << ", size:" << frame.elemSize() << std::endl;
                    return Value({
                        {"__TYPE__", "ImageProcessing::Image"},
                        {"rows", (int64_t)frame.rows},
                        {"cols", (int64_t)frame.cols},
                        {"channels", frame.channels()},
                        {"data", Value(frame.data, frame.rows * frame.cols * frame.elemSize())}
                    });
                }
                return Value::error(logger::error("OpenCVCamera_capture failed. Camera is not initialized."));
            }
        );
    }

}
