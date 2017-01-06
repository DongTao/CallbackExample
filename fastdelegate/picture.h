#ifndef _PICTURE_H_
#define _PICTURE_H_

#include <boost/bind.hpp>
#include <string>
#include <iostream>
using namespace std;

class Picture {
    public:
        Picture(string name):_grs(),_name(name) {
            //_grs.setResultCallback(boost::bind(&Picture::onResultCallback, this));
            _grs.setResultCallback(fastdelegate::MakeDelegate(this, &Picture::onResultCallback));  // fastdelegate
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
