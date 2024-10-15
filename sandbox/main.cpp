#include <engine/Engine.h>
#include <engine/Entry.h>
#include <iostream>

class Sandbox final : public engine::GameScript {
private:
    engine::Window window;
    engine::UserInterface ui;

public:
    Sandbox():window(engine::WindowStyle::RESIZABLE)
    {}

    void init() override {
        window.show("Caravaggio", 600, 400);
        ui.setWindow(&window);
        engine::DrawArea& area = ui.setCurrentState(0);
        engine::FontSystem::registerFont("HP simplified", "hp.cfb");
        engine::Text text("primo testo", "HP simplified");
        area.add(text);
        std::cout << "Sandbox" << std::endl;
    }

    void update() override {
        window.forEachEvent(std::function<void(engine::Event&)>([this](engine::Event& event) {
            this->processEvent(event);
        }));
    }

    void exit() override {
        std::cout << "Exit" << std::endl;
    }

    // user defined functions
    void processEvent(engine::Event& event) {
        switch(event.getEventType()) {
            case engine::EventType::WINDOW_CLOSE:
                engine::Application::close();
                break;
        }
    }

};

GAME_SCRIPT(Sandbox)