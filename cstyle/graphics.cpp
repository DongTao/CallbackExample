#include <graphics.h>
#include <callback.h>
#include <cwrapper.h>
#include <iostream>
#include <queue>

using namespace std;

queue<ResultCallBackEvent> cbq1;
queue<NotNeedCallBackEvent> cbq2;

void* threadResultCallback(void* arg) {
    while (true) {
        if (cbq1.empty()) {
            sleep(2);
            continue;
        }
        ResultCallBackEvent evt = cbq1.front();
        if (evt.cb) {
            evt.cb(evt.ctx);
        }
        cbq1.pop();
    }
}

void* threadNotNeedCallback(void* arg) {
    while (true) {
        if (cbq2.empty()) {
            sleep(2);
            continue;
        }
        NotNeedCallBackEvent evt = cbq2.front();
        if (evt.cb) {
            evt.cb(evt.ctx);
        }
        cbq2.pop();
    }
}

void start_thread() {
    pthread_t tid1;
    pthread_create(&tid1, NULL, threadResultCallback, NULL);
    pthread_t tid2;
    pthread_create(&tid2, NULL, threadNotNeedCallback, NULL);
}

class Graphics::Impl {
    public:
        Impl(void* ctx):ctx_(ctx) {}
        void setResultCallback(ResultCallback cb) {
            rcbe_.cb = cb;
            rcbe_.ctx = ctx_;
        }
        void setNotNeedCallback(NotNeedCallback cb) {
            ncbe_.cb = cb;
            ncbe_.ctx = ctx_;
        }

        void drawLine(int x0, int y0, int x1, int y1);
        void drawRectangle(int x0, int y0, int x1, int y1);
        void drawCircle(int x0, int y0, int r);
    private:
        ResultCallBackEvent rcbe_;
        NotNeedCallBackEvent ncbe_;
        void* ctx_;
};

void Graphics::Impl::drawLine(int x0, int y0, int x1, int y1) {
    cout << "draw line impl (" << x0 << "," << y0 << "," << x1 << "," << y1 << ")" << endl;
    cbq1.push(rcbe_);
}

void Graphics::Impl::drawRectangle(int x0, int y0, int x1, int y1) {
    cout << "draw rectangle impl (" << x0 << "," << y0 << "," << x1 << "," << y1 << ")" << endl;
    cbq2.push(ncbe_);
}

void Graphics::Impl::drawCircle(int x0, int y0, int r) {
    cout << "draw circle impl (" << x0 << "," << y0 << "," << r << ")" << endl;
    cbq1.push(rcbe_);
}

Graphics::Graphics(void* ctx):impl(new Impl(ctx)) {
}

Graphics::~Graphics() {
}

void Graphics::setResultCallback(ResultCallback cb) {
    impl->setResultCallback(cb);
}

void Graphics::setNotNeedCallback(NotNeedCallback cb) {
    impl->setNotNeedCallback(cb);
}

void Graphics::drawLine(int x0, int y0, int x1, int y1) {
    impl->drawLine(x0, y0, x1, y1);
}

void Graphics::drawRectangle(int x0, int y0, int x1, int y1) {
    impl->drawRectangle(x0, y0, x1, y1);
}

void Graphics::drawCircle(int x0, int y0, int r) {
    impl->drawCircle(x0, y0, r);
}
