#pragma once

#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web;
using namespace http;
using namespace http::experimental::listener;

class RouteHandler {
public:
    void handle_get(http_request request);
    void handle_post(http_request request);
    void handle_put(http_request request);
    void handle_delete(http_request request);
};
