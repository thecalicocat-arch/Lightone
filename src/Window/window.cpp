#include "window.h"
#include <iostream>

Window::Window()
{ 
    if (!this->m_window_object)
    {
        std::cout << "[init.GLFWwindow] Ocorreu um erro ao criar a janela." << std::endl;
    }

    if (!glfwInit())
    {
        glfwTerminate();
        std::cout << "[init.glfwInit] Não foi possível iniciar o glfw." << std::endl;
    }
}

 Window::~Window() {
    glfwDestroyWindow(this->m_window_object);
}

void Window::Create(int width, int height, const char *title)
{
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Vamos passar o Vulkan manualmente
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    this->m_window_object = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!this->m_window_object)
    {
        std::cout << "[init.glfwCreateWindow] Não foi gerar a janela." << std::endl;
    }

    while (!glfwWindowShouldClose(this->m_window_object))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(this->m_window_object);

        glfwPollEvents();
    }

    glfwDestroyWindow(this->m_window_object);
}

void Window::Visible(bool isVisible)
{
    if (!this->m_window_object)
    {
        std::cout << "[init.glfwCreateWindow] Não é possível gerar a janela antes de iniciá-la." << std::endl;
        return;
    }

    if (isVisible)
    {
        glfwShowWindow(this->m_window_object);
        glfwMakeContextCurrent(this->m_window_object);
    }
    else
    {
        glfwHideWindow(this->m_window_object);
    }
}