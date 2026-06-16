#pragma once
#include <glfw/glfw3.h>

int init(int largura, int altura, char* title);


class Window {
    private: 
        const char* m_title;
        GLFWwindow* m_window_object;
    public:
        Window();
        ~Window();

        void Create(int width, int height, const char* title);
        void Visible(bool isVisible);
};