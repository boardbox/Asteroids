#include <cstdio>
#include <vector>
#include <GL/glfw.h>
#include "WinMgr.h"
#include "Object.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Input.h"

int running = 1;  //controls game loop
int reloadt = 6;

void mainGameLoop(Player &p, Input &in){
	std::vector<Asteroid*> rocks;
	rocks.push_back(new Asteroid(100,100,40,1,0,640,480));
	rocks.push_back(new Asteroid(400,400,40,3,3,640,480));
	rocks.push_back(new Asteroid(100,300,40,-1,-3,640,480));

	std::vector<Bullet*> bullets;

	while(running){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		in.getInput();
		if(glfwGetTime() > 0.03){
			if(reloadt > 5) reloadt++;
			else{
				p.fired = 0;
				reloadt++;
			}
			if(p.fired){
				bullets.push_back(new Bullet(p));
				p.fired = 0;
				reloadt = 0;
			}
			p.move();
			for(int i = 0;i<rocks.size();i++){
				rocks[i]->move();
				if(p.collided(*rocks[i])) running = 0;
			}
			for(int i = 0;i<bullets.size();i++){
				bullets[i]->move();
				for(int j = 0;j<rocks.size();j++){
					if(bullets[i]->collided(*rocks[j])){
						double x,y,s;
						rocks[j]->xysInfo(x,y,s);
						rocks.push_back(new Asteroid(x,y,s/2.0,rocks[j]->vel.y,-rocks[j]->vel.x,640,480));
						rocks.push_back(new Asteroid(x,y,s/2.0,-rocks[j]->vel.y,rocks[j]->vel.x,640,480));
						bullets.erase(bullets.begin()+i);
						rocks.erase(rocks.begin()+j);
					}
				}
				if(bullets[i]->isDead()){
					bullets.erase(bullets.begin()+i);
				}
			}
			glfwSetTime(0);
		}
		p.draw();
		for(int i = 0;i<rocks.size();i++) rocks[i]->draw();
		for(int i = 0;i<bullets.size();i++) bullets[i]->draw();
		glfwSwapBuffers();
	}
}

int
main(void){
	//set up window/OpenGL
	WinMgr *win = new WinMgr();
	Player p(640,480);
	Input in(p,running);
	
	//loop game
	glfwSetTime(0.0);
	while(true){
		mainGameLoop(p,in);
		
		if(!running) break;
	}

	//take down window/OpenGL
	delete win;

	//exit program
}
