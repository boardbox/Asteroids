#include <GL/glfw.h>
#include "Player.h"
#include "Input.h"

const double s = 0.00025; //speed increment for player
const double r = 0.01; //amount to rotate the normal

Input::Input(Player &pl,int &r):p(pl),run(r){
	glfwEnable(GLFW_STICKY_KEYS);
}

void Input::getInput(){
	//user kills the game
	if(glfwGetKey(GLFW_KEY_ESC)) run = 0;

	if(glfwGetKey(GLFW_KEY_UP)) p.changeSpeed(s);

	if(glfwGetKey(GLFW_KEY_DOWN)) p.changeSpeed(-s);

	if(glfwGetKey(GLFW_KEY_LEFT)) p.rotate(r);

	if(glfwGetKey(GLFW_KEY_RIGHT)) p.rotate(-r);

	if(glfwGetKey(GLFW_KEY_SPACE)) p.fired = true;
};
