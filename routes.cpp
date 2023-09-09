#include "crow_all.h"
#include <sstream> // Include the necessary header for stringstream

// Handler function for the addition route
crow::response add(const crow::request &req)
{
    auto input = crow::json::load(req.body);

    // Check if the JSON is valid
    if (!input || !input.has("num1") || !input.has("num2")) {
        return crow::response(400, "Invalid input");
    }

    // Extract the numbers from the JSON
    double num1 = input["num1"].d();
    double num2 = input["num2"].d();

    // Calculate the result
    double result = num1 + num2;

    // Prepare the response in JSON format
    crow::json::wvalue response;
    response["result"] = result;

    // Serialize the JSON object to a string
    std::ostringstream oss;
    crow::json::wstream(oss, response);

    // Return the response with status code 200 and JSON content
    crow::response res;
    res.code = 200;
    res.set_header("Content-Type", "application/json");
    res.body = oss.str();

    return res;
}

// Handler function for the subtraction route
crow::response subtract(const crow::request &req)
{
    auto input = crow::json::load(req.body);

    // Check if the JSON is valid
    if (!input || !input.has("num1") || !input.has("num2")) {
        return crow::response(400, "Invalid input");
    }

    // Extract the numbers from the JSON
    double num1 = input["num1"].d();
    double num2 = input["num2"].d();

    // Calculate the result
    double result = num1 - num2;

    // Prepare the response in JSON format
    crow::json::wvalue response;
    response["result"] = result;

    // Serialize the JSON object to a string
    std::ostringstream oss;
    crow::json::wstream(oss, response);

    // Return the response with status code 200 and JSON content
    crow::response res;
    res.code = 200;
    res.set_header("Content-Type", "application/json");
    res.body = oss.str();

    return res;
}

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/add")
        .methods("POST"_method)(&add);

    CROW_ROUTE(app, "/subtract")
        .methods("POST"_method)(&subtract);

    app.port(8080).run();

    return 0;
}
