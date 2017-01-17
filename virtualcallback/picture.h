#ifndef _PICTURE_H_
#define _PICTURE_H_

#include "graphics.h"
#include "mycallback.h"
#include <iostream>
#include <string>
using namespace std;

class Picture {
    public:
        Picture(const string& name):
            _cb(this),_grs(&_cb),_name(name) {
        }
        ~Picture() {
        }
        void drawLollipop() {
            _grs.drawCircle(0, 6, 3);
            _grs.drawLine(0, 3, 0, 0);
        }
        //跟cstyle方案一样，对外暴露回调函数，调用结果依赖外部类通知
        void onCallbackResult() {
            cout << "Picture " << _name << " result call back" << endl;
        }
        void onCallbackNotNeed() {
            cout << "Picture " << _name << " not need call back" << endl;
        }

    private:
        MyCallback _cb;
        Graphics _grs;
        string _name;
};

#endif
