#include "Hub.h"


void Hub::wakeupCb(us_loop *loop) {

}

Hub::Hub() {
    loop = us_create_loop(wakeupCb, sizeof(Data));
    new (data = (Data *) us_loop_userdata(loop)) Data();

    // this could lie in Data constructor
    data->httpContext = (HttpContext *) us_create_socket_context(loop, sizeof(HttpContext));
    new (data->httpContext) HttpContext();
}

void Hub::listen(const char *host, int port, int options) {
    data->httpContext->listen(host, port, options);
}

void Hub::run() {
    us_loop_run(loop);
}

Hub::~Hub() {
    // us_loop_delete(loop);
}
