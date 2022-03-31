#include <juiz/juiz.h>
#include <juiz/container.h>

#include "OpenCVCamera.h"

using namespace juiz;


extern "C" {

    JUIZ_OPERATION  void* OpenCVCamera_finalize() {
        return containerOperationFactory<OpenCVCamera>(
            {
              {"typeName", "finalize"},
              {"defaultArg", {
                  {}
              }},
            },
            [](auto& container, auto arg) -> juiz::Value {
                
                if (container.capture_) {
                    container.capture_.reset();
                    return Value{0};
                }
                return Value{-1};
            }
        );
    }

}
