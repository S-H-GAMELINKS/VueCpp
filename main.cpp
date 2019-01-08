#include <httplib.h>
#include <fstream>
#include <sstream>
#include <string>

const std::string LoadAssets(const std::string& path) {

    std::ifstream file(path.c_str(), std::ios::in);
    
    std::stringstream stream;

    stream << file.rdbuf();

    file.close();

    std::string assets(stream.str());

    return assets;
}

int main() {

    httplib::Server svr;

    std::string body = LoadAssets("./assets/index.html");

    svr.Get("/", [&](const httplib::Request& req, httplib::Response& res) {
        res.set_content(body, "text/html");
    });

    svr.listen("localhost", 3000);

    return 0;
}