#ifndef _MYCALLBACK_H_
#define _MYCALLBACK_H_

#include <graphics.h>

using namespace std;

class Picture;
class MyCallback : public CallbackBase {
    public:
        MyCallback(Picture* pic):pic_(pic) {}
        void CallbackResult();
        void CallbackNotNeed();
    private:
        Picture* pic_;
};

#endif
