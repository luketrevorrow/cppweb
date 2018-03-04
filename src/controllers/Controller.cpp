#include "Controller.hpp"

im::controllers::Controller::Controller()
{
    crow::mustache::set_base("views");
}

im::controllers::Controller::~Controller()
{
}

crow::response im::controllers::Controller::createResponse()
{
    context["description"] = "Głównie o moich zainteresowaniach i poglądach.";
    context["author"] = "Igor Mróz";
    context["keywords"] = ""; // TODO Some keywords common for all pages and then add when needed
    context["version"] = im::ApplicationVersion::get();
    context["head"] = crow::mustache::load("head.mstch").render(context);
    context["header"] = crow::mustache::load("header.mstch").render(context);
    context["navigation"] = crow::mustache::load("navigation.mstch").render(context);
    context["footer"] = crow::mustache::load("footer.mstch").render(context);

    crow::response response = crow::response(crow::mustache::load("main.mstch").render(context));
    response.add_header("Content-Type", "text/html; charset=utf-8");
    response.add_header("Content-Length", std::to_string(response.body.size()));

    return response;
}