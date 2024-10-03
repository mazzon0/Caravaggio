#include <engine/Engine.h>
#include <engine/Entry.h>
#include <iostream>
#include <optional>

class Sandbox final : public engine::GameScript {
private:
    engine::Window window;

public:

    void init() override {
        window = engine::Window("Caravaggio", 600, 400);
        std::cout << "Sandbox" << std::endl;
    }

    void update() override {
        std::cout << "Update" << std::endl;
        for(int i=0; i<1000000000; i++) {}
    }

    void exit() override {
        std::cout << "Exit" << std::endl;
    }

};

GAME_SCRIPT(Sandbox)