#include <graphics.h>
#include <callback.h>
#include <iostream>
#include <queue>
#include <unistd.h>

using namespace std;

queue<ResultCallback> cbq1;
queue<NotNeedCallback> cbq2;

void* threadResultCallback(void* arg) {
    while (true) {
        if (cbq1.empty()) {
            sleep(2);
            continue;
        }
        ResultCallback cb = cbq1.front();
        if (cb) {
            cb();
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
        NotNeedCallback cb = cbq2.front();
        if (cb) {
            cb();
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
        Impl() {}
        void setResultCallback(const ResultCallback& cb) {
            _rcb = cb;
        }
        void setNotNeedCallback(const NotNeedCallback& cb) {
            _ncb = cb;
        }

        void drawLine(int x0, int y0, int x1, int y1);
        void drawRectangle(int x0, int y0, int x1, int y1);
        void drawCircle(int x0, int y0, int r);
    private:
        ResultCallback _rcb;
        NotNeedCallback _ncb;
};

void Graphics::Impl::drawLine(int x0, int y0, int x1, int y1) {
    cout << "draw line impl (" << x0 << "," << y0 << "," << x1 << "," << y1 << ")" << endl;
    cbq1.push(_rcb);
}

void Graphics::Impl::drawRectangle(int x0, int y0, int x1, int y1) {
    cout << "draw rectangle impl (" << x0 << "," << y0 << "," << x1 << "," << y1 << ")" << endl;
    cbq2.push(_ncb);
}

void Graphics::Impl::drawCircle(int x0, int y0, int r) {
    cout << "draw circle impl (" << x0 << "," << y0 << "," << r << ")" << endl;
    cbq1.push(_rcb);
}

Graphics::Graphics():impl(new Impl) {
}

Graphics::~Graphics() {

}

void Graphics::setResultCallback(const ResultCallback& cb) {
    impl->setResultCallback(cb);
}

void Graphics::setNotNeedCallback(const NotNeedCallback& cb) {
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
