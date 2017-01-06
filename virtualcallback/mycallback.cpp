#include "mycallback.h"
#include "picture.h"

void MyCallback::CallbackResult() {
    if (_pic) {
        _pic->onCallbackResult();
    }
}
void MyCallback::CallbackNotNeed() {
    if (_pic) {
        _pic->onCallbackNotNeed();
    }
}
