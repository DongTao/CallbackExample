#ifndef _PICTURE_H_
#define _PICTURE_H_

#include <boost/bind.hpp>
#include <string>
#include <iostream>
using namespace std;

class Picture {
    public:
        Picture(string name):_grs(),_name(name) {
            //此处构造函数中注册回调使用this指针的方式线程不安全，仅为演示用，
            //正常应使用二段式构造
            _grs.setResultCallback(boost::bind(&Picture::onResultCallback, this));
        }
        void drawLollipop() {
            _grs.drawCircle(0, 6, 3);
            _grs.drawLine(0, 3, 0, 0);
        }
    private:
        void onResultCallback() {
            cout << "Picture " << _name << " result call back" << endl;
        }
        Graphics _grs;
        string _name;
};

#endif
