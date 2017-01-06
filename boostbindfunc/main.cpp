#include "graphics.h"
#include "picture.h"

int main(void) {
    Picture p1("p1");
    p1.drawLollipop();

    Picture p2("p2");
    p2.drawLollipop();

    Picture p3("p3");
    p3.drawLollipop();

    start_thread();
    sleep(3);
    return 0;
}
