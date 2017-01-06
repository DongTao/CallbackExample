#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <string>
#include <callback.h>
#include <boost/noncopyable.hpp>
using namespace std;

struct ResultCallBackEvent {
    ResultCallback cb;
    void* ctx;
};

struct NotNeedCallBackEvent {
    NotNeedCallback cb;
    void* ctx;
};

class Graphics : boost::noncopyable  {
    public:
        Graphics(void*);
        ~Graphics();

        void setResultCallback(ResultCallback cb);
        void setNotNeedCallback(NotNeedCallback cb);

        void drawLine(int x0, int y0, int x1, int y1);
        void drawCircle(int x0, int y0, int r);
        void drawRectangle(int x0, int y0, int x1, int y1);
    private:
        class Impl;
        Impl* impl;
};

#endif
