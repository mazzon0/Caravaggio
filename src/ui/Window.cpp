#include "engine/ui/Window.h"
#include <iostream>

namespace engine {

    uint16_t Window::s_nWindows = 0;

    Window::Window(std::string title, int width, int height,
        WindowStyle style, bool fullscreen, bool cursorVisible)
        : m_fullscreen(fullscreen),m_cursorVisible(cursorVisible),m_style(style)
    {
        /* TODO: check errors in parameters */

        // initialize glfw library
        if(s_nWindows==0) {
            glfwInit();
        }

        // window initialization
        createWindow(title.c_str(), width, height);
        ++ s_nWindows;
        m_init=true;
    }

    Window::Window(const Window& wnd)
    {
        if(wnd.m_init) {
            m_style = wnd.m_style;
            m_fullscreen = wnd.m_fullscreen;
            m_cursorVisible = wnd.m_cursorVisible;
            m_windowedPos[0] = wnd.m_windowedPos[0]; m_windowedPos[1] = wnd.m_windowedPos[1];
            m_windowedSize[0] = wnd.m_windowedSize[0]; m_windowedSize[1] = wnd.m_windowedSize[1];
            createWindow(glfwGetWindowTitle(wnd.m_pWindow), m_windowedSize[0], m_windowedSize[1]);
        }
        else
            m_init=false;
        
        ++ s_nWindows;
    }

    Window::~Window() {
        destroyWindow();

        // destroy remaining windows just in case
        if(s_nWindows==0) {
            glfwTerminate();
        }
    }

    Window& Window::operator = (const Window& wnd) {
        if(m_init)
            destroyWindow();
        
        if(wnd.m_init) {
            m_style = wnd.m_style;
            m_fullscreen = wnd.m_fullscreen;
            m_cursorVisible = wnd.m_cursorVisible;
            m_windowedPos[0] = wnd.m_windowedPos[0]; m_windowedPos[1] = wnd.m_windowedPos[1];
            m_windowedSize[0] = wnd.m_windowedSize[0]; m_windowedSize[1] = wnd.m_windowedSize[1];
            m_init=true;
            createWindow(glfwGetWindowTitle(wnd.m_pWindow), m_windowedSize[0], m_windowedSize[1]);
        }
        else
            m_init=false;
        
        ++ s_nWindows;
        return *this;
    }

    void Window::setFullscreen(bool fullscreen) {
        GLFWmonitor* monitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;
        glfwSetWindowMonitor(m_pWindow, monitor, m_windowedPos[0], m_windowedPos[1],
            m_windowedSize[0], m_windowedSize[1], GLFW_DONT_CARE);
            m_fullscreen = fullscreen;
    }

    void Window::setCursorVisibility(bool visible) {
        m_cursorVisible = visible;
        if(m_cursorVisible)
            glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        else
            glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }

    bool Window::shouldClose() const {
        return glfwWindowShouldClose(m_pWindow);
    }

    void Window::createWindow(const char* title, int width, int height) {
                // settings to create the window
        switch(m_style) {
            case RESIZABLE:
                glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
                glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
                break;
            case FIXED:
                glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
                glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
                break;
            case POPUP:
                glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
                glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
                break;
            case CUSTOM:
                glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
                glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
                break;
        }
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_TRUE);
        /* TODO: add macOS and X11 related hints */

        GLFWmonitor* monitor = m_fullscreen ? glfwGetPrimaryMonitor() : nullptr;

        // window creation
        m_pWindow = glfwCreateWindow(width, height, title, monitor, nullptr);
        if(m_pWindow==nullptr) {
            std::cout << "ERROR: window failed to be created" << std::endl;
        }

        // initialize remaining attributes
        glfwGetWindowPos(m_pWindow, &m_windowedPos[0], &m_windowedPos[1]);
        glfwGetWindowSize(m_pWindow, &m_windowedSize[0], &m_windowedSize[1]);

        setCursorVisibility(m_cursorVisible);
    }

    void Window::destroyWindow() {
        glfwDestroyWindow(m_pWindow);
        --s_nWindows;
    }

}