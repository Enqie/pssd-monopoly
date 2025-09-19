// Imgui init code based on
// https://github.com/ocornut/imgui/blob/master/examples/example_glfw_opengl3/main.cpp

#include "./imgui/backends/imgui_impl_glfw.h"
#include "./imgui/backends/imgui_impl_opengl3.h"
#include "./imgui/imgui.h"
#include "./imgui/misc/cpp/imgui_stdlib.h"
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // GL + GLSL version
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Monopoly", nullptr, nullptr);
    if (window == nullptr)
    glfwMakeContextCurrent(window);
    //glfwSwapInterval(1); // vsync
}