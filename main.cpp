#include <iostream>
#include <fstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

using namespace ImGui;


void Authentication();

bool authenticated = false;

char InputUsername[1024] = { 0 };
char InputPassword[1024] = { 0 };

int main()
{
    //starts the window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "Login Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    gladLoadGL();
    glViewport(0, 0, 800, 800);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window)) 
    {
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImVec2 WindowSize = GetWindowSize();
        int WindowX = WindowSize.x;
        int WindowY = WindowSize.y;

        if (!authenticated)
        {
            
   
            // USERNAME FUNCTION AND STYLING
            SetCursorPos(ImVec2((WindowX / 2) - 75, WindowY / 2));
            SetNextItemWidth(150.0f);
            InputText("##", InputUsername, IM_ARRAYSIZE(InputUsername));

            SetCursorPos(ImVec2((WindowX / 2) - 25, (WindowY / 2) - 18));
            Text("USERNAME");
            

            // PASSWORD FUNCTION AND STYLYING
            SetCursorPos(ImVec2((WindowX / 2) - 75,(WindowY / 2) + 35));
            SetNextItemWidth(150.f);
            InputText("###", InputPassword, IM_ARRAYSIZE(InputPassword), ImGuiInputTextFlags_Password);

            SetCursorPos(ImVec2((WindowX / 2) - 25,(WindowY / 2) + 22));
            Text("PASSWORD");

            SetCursorPos(ImVec2((WindowX / 2) - 20, (WindowY / 2) + 65));
            if (Button("LOGIN"))
            {
                Authentication();
            }
        }


        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;

}   
    
    
    
    
    
    
void Authentication()
{
    std::cout << "This works" << std::endl;
    std::cout << "Username: " << InputUsername << std::endl;
    std::cout << "Password: " << InputPassword << std::endl;

}
