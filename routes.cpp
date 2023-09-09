#include "crow_all.h" 
#include <sstream> // Include the necessary header for stringstream 
 
// Handler function for the addition route 
crow::response add(const crow::request &req) 
{ 
    auto input = crow::json::load(req.body); 
     
    // Check if the JSON is valid 
    if (!input  !input.has("first")  !input.has("second")) { 
        return crow::response(400, "Invalid JSON format"); 
    } 
 
    // Extract the numbers from the JSON 
    int first = input["first"].i(); 
    int second = input["second"].i(); 
     
    // Calculate the result 
    int result = first + second; 
 
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
 
    CROW_ROUTE(app, "/calculator/add") 
        .methods("POST"_method)(&add); 
 
    app.port(8080).run(); 
 
    return 0; 
}
