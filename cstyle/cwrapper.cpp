#include "cwrapper.h"
#include "graphics.h"
#include <map>
#include <boost/atomic.hpp>
#include <boost/smart_ptr.hpp>

std::map<GraphicsHandler, boost::shared_ptr<Graphics> > HANDLE_MAP;
boost::atomic_int HANDLE_INDEX(0);

GraphicsHandler CreateGraphicsHandler(void* ctx) {
    int index = ++HANDLE_INDEX;
    HANDLE_MAP[index] = boost::make_shared<Graphics>(ctx);
    return index;
}

void DestroyGraphicsHandler(GraphicsHandler handle) {
    if (HANDLE_MAP.find(handle) != HANDLE_MAP.end()) {
        HANDLE_MAP.erase(HANDLE_MAP.find(handle));
    }
}

bool SetResultCallback(GraphicsHandler handle, ResultCallback cb) {
    if (HANDLE_MAP.find(handle) != HANDLE_MAP.end()) {
        HANDLE_MAP.find(handle)->second->setResultCallback(cb);
        return true;
    }
    return false;
}

bool SetNotNeedCallback(GraphicsHandler handle, NotNeedCallback cb) {
    if (HANDLE_MAP.find(handle) != HANDLE_MAP.end()) {
        HANDLE_MAP.find(handle)->second->setNotNeedCallback(cb);
        return true;
    }
    return false;
}

bool DrawLine(GraphicsHandler handle, int x0, int y0, int x1, int y1) {
    if (HANDLE_MAP.find(handle) != HANDLE_MAP.end()) {
        HANDLE_MAP.find(handle)->second->drawLine(x0, y0, x1, y1);
        return true;
    }
    return false;
}

bool DrawCircle(GraphicsHandler handle, int x0, int y0, int r) {
    if (HANDLE_MAP.find(handle) != HANDLE_MAP.end()) {
        HANDLE_MAP.find(handle)->second->drawCircle(x0, y0, r);
        return true;
    }
    return false;
}

bool DrawRectangle(GraphicsHandler handle, int x0, int y0, int x1, int y1) {
    if (HANDLE_MAP.find(handle) != HANDLE_MAP.end()) {
        HANDLE_MAP.find(handle)->second->drawRectangle(x0, y0, x1, y1);
        return true;
    }
    return false;
}
