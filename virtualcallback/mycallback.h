#ifndef _MYCALLBACK_H_
#define _MYCALLBACK_H_

#include <graphics.h>

using namespace std;

class Picture;
//需要实现自己的回调类，比起bind和fastdelegate，有以下缺陷：
//1.函数名被严格限定；
//2.需要实现所有虚回调函数(CallbackNotNeed函数就用不着)；
//3.回调类与接口类耦合(继承关系)
//4.库接口存在虚函数会导致二进制兼容性较差
class MyCallback : public CallbackBase {
    public:
        MyCallback(Picture* pic):pic_(pic) {}
        void CallbackResult();
        void CallbackNotNeed();
    private:
        Picture* pic_;
};

#endif
