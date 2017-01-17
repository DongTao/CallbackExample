#include "mycallback.h"
#include "picture.h"

void MyCallback::CallbackResult() {
    if (pic_) {
        pic_->onCallbackResult();
    }
}
void MyCallback::CallbackNotNeed() {
    if (pic_) {
        pic_->onCallbackNotNeed();
    }
}
