#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <Vector3.h>
#include <Matrix3.h>



class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	void setCubePositions();
	float rotationAngle = 0.0f;
	std::vector<Vector3> cube;

	GLuint index;
	sf::Clock clock;
	sf::Time elapsed;
};