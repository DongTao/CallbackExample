#ifndef _PICTURE_H_
#define _PICTURE_H_

#include <string>
#include <iostream>
#include "cwrapper.h"
using namespace std;

class Picture {
    public:
        Picture(string name):name_(name),handle_(CreateGraphicsHandler(reinterpret_cast<void*>(this))) {
            SetResultCallback(handle_, callbackPicture);
        }
        static void callbackPicture(void* ctx) {
            if (ctx == NULL) {
                cout << "callback lost: ctx NULL!" << endl;
                return;
            }
            Picture* ptr = reinterpret_cast<Picture*>(ctx);
            ptr->onResultCallback();
        }
        void drawLollipop() {
            DrawCircle(handle_, 0, 6, 3);
            DrawLine(handle_, 0, 3, 0, 0);
        }
        // 该回调函数需要对外暴露，并不是一个好的实现
        void onResultCallback() {
            cout << "Picture " << name_ << " result call back" << endl;
        }
    private:
        string name_;
        GraphicsHandler handle_;
};

#endif
