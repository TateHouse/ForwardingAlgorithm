#include "Application.hpp"

int main(int argc, char* argv[]) {
    Console::Application application {};
    application.initialize();

    while (application.getIsRunning()) {
        application.update();
    }

    application.shutdown();

    return 0;
}