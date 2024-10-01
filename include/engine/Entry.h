#include "engine/application/Application.h"

engine::GameScript* getGameScript();

int main(int argc, char* argv[]) {
    engine::Application::init(argv[0], getGameScript());
    engine::Application::run();
    engine::Application::exit();
}