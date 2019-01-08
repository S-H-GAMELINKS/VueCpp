#include <httplib.h>
#include <fstream>
#include <sstream>
#include <string>

int main() {

    httplib::Server svr;

    std::ifstream file("./assets/index.html", std::ios::in);

    std::stringstream stream;

    stream << file.rdbuf();
    file.close();

    std::string body(stream.str());

    svr.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content(body, "text/html");
    });

    svr.listen("localhost", 3000);

    return 0;
}