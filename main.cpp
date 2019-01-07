#include <httplib.h>

int main() {

    httplib::Server svr;

    svr.set_base_dir("./assets");

    svr.listen("localhost", 3000);

    return 0;
}