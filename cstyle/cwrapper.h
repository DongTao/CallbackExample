#ifndef _C_WRAPPER_H_
#define _C_WRAPPER_H_

#include <callback.h>

extern "C" {
    typedef int GraphicsHandler;
    void start_thread();

    GraphicsHandler CreateGraphicsHandler(void* ctx);
    void DestroyGraphicsHandler(GraphicsHandler handle);

    bool SetResultCallback(GraphicsHandler handle, ResultCallback cb);
    bool SetNotNeedCallback(GraphicsHandler handle, NotNeedCallback cb);

    bool DrawLine(GraphicsHandler handle, int x0, int y0, int x1, int y1);
    bool DrawCircle(GraphicsHandler handle, int x0, int y0, int r);
    bool DrawRectangle(GraphicsHandler handle, int x0, int y0, int x1, int y1);
}
#endif
