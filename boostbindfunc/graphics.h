#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <string>
#include <callback.h>
using namespace std;

class Graphics {
    public:
        Graphics();
        ~Graphics();

        void setResultCallback(const ResultCallback& cb);
        void setNotNeedCallback(const NotNeedCallback& cb);

        void drawLine(int x0, int y0, int x1, int y1);
        void drawCircle(int x0, int y0, int r);
        void drawRectangle(int x0, int y0, int x1, int y1);
    private:
        //Graphics为接口类，使用pImpl手法隔离实现
        class Impl;
        Impl* impl;
};

void start_thread();
#endif
