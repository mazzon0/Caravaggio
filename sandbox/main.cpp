#include <engine/Engine.h>
#include <engine/Entry.h>
#include <iostream>

class Sandbox final : public engine::GameScript {
    void init() override {
        std::cout << "Sandbox" << std::endl;
    }

    void update() override {
        std::cout << "Update" << std::endl;
    }

    void exit() override {
        std::cout << "Exit" << std::endl;
    }

};

GAME_SCRIPT(Sandbox)