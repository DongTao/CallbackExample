#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <boost/shared_ptr.hpp>

class CallbackBase {
    public:
        virtual ~CallbackBase() {}
        virtual void CallbackResult() = 0;
        virtual void CallbackNotNeed() = 0;
};

class Graphics {
    public:
        Graphics(CallbackBase*);
        ~Graphics();

        void drawLine(int x0, int y0, int x1, int y1);
        void drawCircle(int x0, int y0, int r);

        void drawRectangle(int x0, int y0, int x1, int y1);
    private:
        class Impl;
        boost::shared_ptr<Impl> impl;
};

void start_thread();
#endif
