#ifndef CRVG_WINDOW
#define CRVG_WINDOW

#include <string>
#include <glfw/glfw3.h>

namespace engine {

    // forward declarations (ignore)
    class Window;
    namespace Input {
        bool isKeyDown(const Window&, int);
        void getCursorPos(const Window&, double*, double*);
    }   // end of forward declarations

    enum WindowStyle {
        RESIZABLE,
        FIXED,
        POPUP,
        CUSTOM
    };

    /* TODO: add event callbacks, icon support (glfwSetWindowIcon), cursor (glfwSetCursor) */
    class Window {
    public:
        Window(std::string title, int width, int height,
            WindowStyle style = RESIZABLE, bool fullscreen = false, bool cursorVisible = true);
        ~Window();

        Window() {m_init=false;}    // does not open any window
        Window(const Window& wnd);
        Window& operator = (const Window& wnd);

        /* TODO: title get set */
        void setFullscreen(bool fullscreen);
        bool getFullscreen() const {return m_fullscreen;}
        void setCursorVisibility(bool visible);
        bool getCursorVisibility() const {return m_cursorVisible;}
        bool shouldClose() const;

    private:
        void createWindow(const char* title, int width, int height);
        void destroyWindow();

    private:
        GLFWwindow* m_pWindow;
        WindowStyle m_style;
        bool m_fullscreen;
        bool m_cursorVisible;
        int m_windowedPos[2];
        int m_windowedSize[2];

        // allow reinitialization
        bool m_init;

        static uint16_t s_nWindows;

        friend bool Input::isKeyDown(const Window&, int);
        friend void Input::getCursorPos(const Window&, double*, double*);
    };

}

#endif
