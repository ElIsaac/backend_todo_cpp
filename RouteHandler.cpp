#include "RouteHandler.h"

void RouteHandler::handle_get(http_request request) {
    json::value response;
    response["message"] = json::value::string("Hola Mundo desde GET");
    request.reply(status_codes::OK, response);
}

void RouteHandler::handle_post(http_request request) {
    json::value response;
    response["message"] = json::value::string("Hola Mundo desde POST");
    request.reply(status_codes::OK, response);
}

void RouteHandler::handle_put(http_request request) {
    json::value response;
    response["message"] = json::value::string("Hola Mundo desde PUT");
    request.reply(status_codes::OK, response);
}

void RouteHandler::handle_delete(http_request request) {
    json::value response;
    response["message"] = json::value::string("Hola Mundo desde DELETE");
    request.reply(status_codes::OK, response);
}
