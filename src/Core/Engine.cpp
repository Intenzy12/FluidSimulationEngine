#include <glad/glad.h>
#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>
#include "Core/Engine.h"
#include "Core/Error.h"
#include "GLFW/glfw3.h"
#include <iostream>

Engine* Engine::minstance = NULL;

Engine::Engine(): mrunning(true)
{
	minstance = this;

	mwindowdata.width = 1024;
	mwindowdata.height = 720;
	mwindowdata.title = "Fluid Simulation Engine";
}

Engine::~Engine()
{

}

void Engine::run()
{
	initGlfw();
	initImGui();
	loop();
	terminate();
}

void Engine::initGlfw()
{
	if (!glfwInit())
		FatalError("Failed to initialize glfw");

	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	mwindow = glfwCreateWindow(mwindowdata.width, mwindowdata.height, mwindowdata.title, NULL, NULL);
	if (!mwindow)
		FatalError("Failed to create glfw window");

	glfwMakeContextCurrent(mwindow);

	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
		FatalError("Failed to initialize glad");

	glViewport(0, 0, mwindowdata.width, mwindowdata.height);
}

void Engine::initImGui()
{
	ImGui::CreateContext();
	/* ImGuiIO& io = ImGui::GetIO(); */

	ImGui_ImplOpenGL3_Init();
	ImGui_ImplGlfw_InitForOpenGL(mwindow, false);

	glfwSetKeyCallback(mwindow, ImGui_ImplGlfw_KeyCallback);
	glfwSetScrollCallback(mwindow, ImGui_ImplGlfw_ScrollCallback);
	glfwSetMouseButtonCallback(mwindow, ImGui_ImplGlfw_MouseButtonCallback);
	glfwSetCursorPosCallback(mwindow, ImGui_ImplGlfw_CursorPosCallback);
}

void Engine::loop()
{
	while (mrunning)
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		ImGui_ImplGlfw_NewFrame();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		ImGui::ShowDemoWindow();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(mwindow);
		mrunning = !glfwWindowShouldClose(mwindow);
	}
}

void Engine::terminate()
{
	glfwDestroyWindow(mwindow);

	glfwTerminate();
}
