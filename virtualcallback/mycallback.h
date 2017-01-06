#ifndef _MYCALLBACK_H_
#define _MYCALLBACK_H_

#include <graphics.h>

using namespace std;

class Picture;
class MyCallback : public CallbackBase {
    public:
        MyCallback(Picture* pic):_pic(pic) {}
        void CallbackResult();
        void CallbackNotNeed();
    private:
        Picture* _pic;
};

#endif
