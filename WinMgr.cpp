#include <cstdio>
#include <cstdlib>
#include <GL/glfw.h>
#include "WinMgr.h"

//default constructor
//creates asteroid window
WinMgr::WinMgr(){
	//start glfw
	if(!glfwInit()){
		fprintf(stderr,"Call to glfwInit() failed\n");
		exit(-1);
	}
	
	//creates default glfw window
	if(!glfwOpenWindow(0,0,0,0,0,0,0,0,GLFW_WINDOW)){
		fprintf(stderr,"Call to glfwOpenWindow() failed\n");
		glfwTerminate();
		exit(-1);
	}

	glfwSetWindowTitle("Asteroids");
	glClearColor(0,0,0,0);
	gluOrtho2D(0,640,0,480);	
}

WinMgr::~WinMgr(){

	glfwCloseWindow();
	glfwTerminate();
}
