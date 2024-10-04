#ifndef CRVG_WINDOW
#define CRVG_WINDOW

#include "engine/events/EventSystem.h"
#include <string>
#include <utility>
#include <glfw/glfw3.h>

namespace engine {

    // forward declarations (ignore)
    class Window;
    namespace Input {
        bool isKeyDown(const Window&, int);
        void getCursorPos(const Window&, double*, double*);
        bool isButtonPressed(const Window&, int);
    }   // forward declarations

    enum WindowStyle {
        RESIZABLE,
        FIXED,
        POPUP,
        CUSTOM
    };

    /* TODO: icon support (glfwSetWindowIcon), cursor (glfwSetCursor) */
    class Window {
    public:
        Window(WindowStyle style, bool fullscreen = false, bool cursorVisible = true);
        ~Window();

        Window() = delete;
        Window(const Window& wnd) = delete;
        Window& operator = (const Window& wnd) = delete;

        void setTitle(std::string title);
        std::string getTitle();
        void setFullscreen(bool fullscreen);
        bool getFullscreen() const {return m_fullscreen;}
        void setCursorVisibility(bool visible);
        bool getCursorVisibility() const {return m_cursorVisible;}
        bool shouldClose() const;
        void show(std::string title, int width, int height);

        void addKeyEvent(int key, int scancode, int action, int mods);
        void addCharEvent(uint32_t codepoint, int mods);
        void addDropEvent(int count, const char* paths[]);
        void addScrollEvent(double dx, double dy);
        void addCursorEnterEvent(int entered);
        void addCursorPosEvent(double x, double y);
        void addMouseButtonEvent(int button, int actions, int mods);

    private:
        GLFWwindow* m_pWindow;
        WindowStyle m_style;
        bool m_fullscreen;
        bool m_cursorVisible;
        int m_windowedPos[2];
        int m_windowedSize[2];
        bool m_isShowing;
        EventSystem m_eventSystem;

        static uint16_t s_nWindows;

        friend bool Input::isKeyDown(const Window&, int);
        friend void Input::getCursorPos(const Window&, double*, double*);
        friend bool Input::isButtonPressed(const Window&, int);
    };

    Window* getWindow(GLFWwindow* wnd);
    void keyCallback(GLFWwindow* wnd, int key, int scancode, int action, int mods);
    void charCallback(GLFWwindow* wnd, uint32_t codepoint, int mods);
    void dropCallback(GLFWwindow* wnd, int count, const char* paths[]);
    void scrollCallback(GLFWwindow* wnd, double dx, double dy);
    void cursorEnterCallback(GLFWwindow* wnd, int entered);
    void cursorPosCallback(GLFWwindow* wnd, double x, double y);
    void mouseButtonCallback(GLFWwindow* wnd, int button, int action, int mods);

}

#endif
