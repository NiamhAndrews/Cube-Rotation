#include <Game.h>

bool updatable = false;




Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning){

		std::cout << "Game running..." << std::endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.0f, 0.0f, -5.0f);
	glEnable(GL_CULL_FACE);


	cube.push_back(Vector3(-1.0f, -1.0f, 1.0f));//0
	cube.push_back(Vector3(1.0f, -1.0f, 1.0f));//1
	cube.push_back(Vector3(1.0f, 1.0f, 1.0f));//2
	cube.push_back(Vector3(-1.0f,1.0f,1.0f));//3
	cube.push_back(Vector3(-1.0f,-1.0f,-1.0f));//4
	cube.push_back(Vector3(1.0f, -1.0f, -1.0f));//5
	cube.push_back(Vector3(1.0f, 1.0f, -1.0f));//6
	cube.push_back(Vector3(-1.0f, 1.0f, -1.0f));//7

	





}


void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f / 60.0f)
	{
		clock.restart();

		for (Vector3 &vector : cube)
		{
			vector = Matrix3::RotationX(0.5) * vector;
			vector = Matrix3::RotationY(0.5) * vector;
		}


		setCubePositions();

	}
	
	std::cout << "Update up" << std::endl;
}

void Game::draw()
{
	std::cout << "Drawing" << std::endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	std::cout << "Drawing Cube " << std::endl;
	//glLoadIdentity();
	
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on z Axis
	//glRotatef(rotationAngle, 0, 1, 0); // Rotates the camera on z Axis
	//glTranslatef(0.0f, 0.0f, -5.0f);

	glCallList(1);

	window.display();

}

void Game::unload()
{
	std::cout << "Cleaning up" << std::endl;
}



void Game::setCubePositions()
{

	// Creates a new Display List
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{




		//Front
		//T1
		glColor3f(1.0f, 0.3f, 0.0f);
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z); //T1#
		glVertex3f(cube.at(1).x, cube.at(1).y, cube.at(1).z);
		glVertex3f(cube.at(2).x, cube.at(2).y, cube.at(2).z);

		//T2
		glColor3f(0.6f, 0.0f, 0.0f);
		glVertex3f(cube.at(2).x, cube.at(2).y, cube.at(2).z); //T2
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z);
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z);

		//Left
		//T3
		glColor3f(0.8f, 0.0f, 0.0f);
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z); //T3
		glVertex3f(cube.at(7).x, cube.at(7).y, cube.at(7).z);
		glVertex3f(cube.at(4).x, cube.at(4).y, cube.at(4).z);

		//T4
		glColor3f(0.9f, 0.4f, 0.0f);
		glVertex3f(cube.at(4).x, cube.at(4).y, cube.at(4).z); //T4
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z);
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z);

		//Back
		//T5
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(cube.at(4).x, cube.at(4).y, cube.at(4).z); //T5
		glVertex3f(cube.at(7).x, cube.at(7).y, cube.at(7).z);
		glVertex3f(cube.at(6).x, cube.at(6).y, cube.at(6).z);

		//T6
		glColor3f(0.0f, 0.9f, 0.8f);
		glVertex3f(cube.at(6).x, cube.at(6).y, cube.at(6).z); //T6
		glVertex3f(cube.at(5).x, cube.at(5).y, cube.at(5).z);
		glVertex3f(cube.at(4).x, cube.at(4).y, cube.at(4).z);

		//Right
		//T7
		glColor3f(0.4f, 1.0f, 0.0f);
		glVertex3f(cube.at(6).x, cube.at(6).y, cube.at(6).z); //T7
		glVertex3f(cube.at(2).x, cube.at(2).y, cube.at(2).z);
		glVertex3f(cube.at(1).x, cube.at(1).y, cube.at(1).z);

		//T8
		glColor3f(0.0f, 0.5f, 0.5f);
		glVertex3f(cube.at(1).x, cube.at(1).y, cube.at(1).z); //T8
		glVertex3f(cube.at(5).x, cube.at(5).y, cube.at(5).z);
		glVertex3f(cube.at(6).x, cube.at(6).y, cube.at(6).z);


		//Top
		//T9
		glColor3f(0.1f, 0.6f, 0.3f);
		glVertex3f(cube.at(6).x, cube.at(6).y, cube.at(6).z); //T9
		glVertex3f(cube.at(7).x, cube.at(7).y, cube.at(7).z);
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z);
		

		//Top
		//T10
		glColor3f(0.0f, 0.4f, 0.3f);
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z); //T10
		glVertex3f(cube.at(2).x, cube.at(2).y, cube.at(2).z);
		glVertex3f(cube.at(6).x, cube.at(6).y, cube.at(6).z);

		//Bottom
		//T11
		glColor3f(0.5f, 0.4f, 0.0f);
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z); //T11
		glVertex3f(cube.at(4).x, cube.at(4).y, cube.at(4).z);
		glVertex3f(cube.at(5).x, cube.at(5).y, cube.at(5).z);

		//T12
		glColor3f(0.7f, 0.4f, 0.0f);
		glVertex3f(cube.at(5).x, cube.at(5).y, cube.at(5).z); //T12
		glVertex3f(cube.at(1).x, cube.at(1).y, cube.at(1).z);
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z);



	}
	glEnd();
	glEndList();


}

