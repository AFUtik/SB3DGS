//Almost all of the contents of this file are temporary and are used just for testing purposes


#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "constants.h"
#include "mesh.h"
#include "image.h"
#include "shaders.h"
#include "text.h"
#include "button.h"
#include "camera.h"
#include "shader.hpp"

#include <memory>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}  

int Launch()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	glfwWindowHint(GLFW_DEPTH_BITS, 24);
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "SB3DGS", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  
	glfwMakeContextCurrent(window);

	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	

	if (window == NULL || !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){std::cout << "error" << std::endl;glfwTerminate();return -1;}
	std::unique_ptr<BasicShader> shader = std::make_unique<BasicShader>(VlmVxShader, VlmFgShader);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	double mouseX, mouseY;

	int h = 0;

	Text text(-1, 0.9, 4, 2, 0.1);
	text.SetFont("BFont.png");

	Text greettext(-0.9, 0, 25, 3, 0.06);
	greettext.SetFont("BFont.png");
	greettext.SetText("This program does not work yet, but probably will. That's all for now");
	greettext.Update();

	Button but(-0.7f, 0.90f, 0.6f, 0.2f);
	but.SetCall(
		[&h]()
		{
		h++;
			
		}
	);

	bool click = false;


	Camera cam;

	Mesh obj;
	obj.SetTexture("buttonfill.png");

	obj.AddPoint(Point(-1, 0, 1, 0, 0));
	obj.AddPoint(Point(-1, 0, 0, 0, 1));
	obj.AddPoint(Point( 1, 0, 0, 1, 1));
	obj.AddPoint(Point( 1, 0, 1, 1, 0));

	obj.AddFace(0,1,2);
	obj.AddFace(2,3,0);

	obj.Init();

	while(!glfwWindowShouldClose(window))
	{
		shader->use();

		shader->uniformMatrix(shader->proj_loc, cam.getProjectionMatrix());
		shader->uniformMatrix(shader->view_loc, cam.getViewMatrix());

		glfwGetCursorPos(window, &mouseX, &mouseY);
		glClearColor(0.5, 0.5, 0.5, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_DEPTH_TEST);
		
		obj.Render(shader.get());

		glDisable(GL_DEPTH_TEST);

		text.SetText(std::to_string(h));

		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && !click)
		{
			click = true; 
			but.Check(shader.get(), mouseX/(WINDOW_WIDTH/2)-1, mouseY/(WINDOW_HEIGHT/2)-1);
		}
		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
		{
			click = false;
		}

		text.Update();
		but.Update();

		shader->uniformMatrix(shader->proj_loc, cam.getOrtho());
		shader->uniformMatrix(shader->view_loc, glm::mat4(1.0f));

		but.Render(shader.get(), mouseX/(WINDOW_WIDTH/2)-1, mouseY/(WINDOW_HEIGHT/2)-1);
		text.Render(shader.get());
		greettext.Render(shader.get());

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
