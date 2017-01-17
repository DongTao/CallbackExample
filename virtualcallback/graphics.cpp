#include <graphics.h>
#include <iostream>
#include <queue>
#include <unistd.h>

using namespace std;

queue<CallbackBase*> q;

void* threadFunc(void* arg) {
    while (true) {
        if (q.empty()) {
            sleep(2);
            continue;
        }
        CallbackBase* cb = q.front();
        if (cb) {
            cb->CallbackResult();
        }
        q.pop();
    }
}

void start_thread() {
    pthread_t tid;
    pthread_create(&tid, NULL, threadFunc, NULL);
}

class Graphics::Impl {
    public:
        Impl(CallbackBase*);
        void drawLine(int x0, int y0, int x1, int y1);
        void drawRectangle(int x0, int y0, int x1, int y1);
        void drawCircle(int x0, int y0, int r);
    private:
        CallbackBase* _callback;
};

Graphics::Impl::Impl(CallbackBase* cb):_callback(cb) {

}
void Graphics::Impl::drawLine(int x0, int y0, int x1, int y1) {
    cout << "draw line impl (" << x0 << "," << y0 << "," << x1 << "," << y1 << ")" << endl;
    q.push(_callback);
}

void Graphics::Impl::drawRectangle(int x0, int y0, int x1, int y1) {
    cout << "draw rectangle impl (" << x0 << "," << y0 << "," << x1 << "," << y1 << ")" << endl;
    q.push(_callback);
}

void Graphics::Impl::drawCircle(int x0, int y0, int r) {
    cout << "draw circle impl (" << x0 << "," << y0 << "," << r << ")" << endl;
    q.push(_callback);
}

Graphics::Graphics(CallbackBase* cb):impl(new Impl(cb)) {

}

Graphics::~Graphics() {

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
