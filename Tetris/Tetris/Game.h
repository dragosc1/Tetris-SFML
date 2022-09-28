#pragma once
#include "Window.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	sf::Time GetElapsed();
	void RestartClock();
	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
private:
	sf::Clock m_clock;
	sf::Time m_elapsed;
	Window m_window;
	float timespent;
	float timestep = 750;
};

