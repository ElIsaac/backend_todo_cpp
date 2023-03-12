#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "RouteHandler.h"

using namespace web;
using namespace http;
using namespace http::experimental::listener;

void set_routes(http_listener& listener, RouteHandler& route_handler) {
    listener.support(methods::GET, std::bind(&RouteHandler::handle_get, &route_handler, std::placeholders::_1));
    listener.support("/get", std::bind(&RouteHandler::handle_get, &route_handler, std::placeholders::_1));

    listener.support(methods::POST, std::bind(&RouteHandler::handle_post, &route_handler, std::placeholders::_1));
    listener.support("/post", std::bind(&RouteHandler::handle_post, &route_handler, std::placeholders::_1));

    listener.support(methods::PUT, std::bind(&RouteHandler::handle_put, &route_handler, std::placeholders::_1));
    listener.support("/put", std::bind(&RouteHandler::handle_put, &route_handler, std::placeholders::_1));

    listener.support(methods::DEL, std::bind(&RouteHandler::handle_delete, &route_handler, std::placeholders::_1));
    listener.support("/delete", std::bind(&RouteHandler::handle_delete, &route_handler, std::placeholders::_1));
}

void start_server() {
    http_listener listener("http://localhost:8080");
    RouteHandler route_handler;
    set_routes(listener, route_handler);

    try {
        listener.open().wait();
        std::cout << "Listening on http://localhost:8080\n";
        std::cin.get();
        listener.close().wait();
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    start_server();
    return 0;
}
