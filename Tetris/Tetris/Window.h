#pragma once
#include <SFML/Graphics.hpp>
class Window
{
public:
	// Constructors / Destructors
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();

	// Drawing
	void BeginDraw(); // Clear the window.
	void Draw(sf::Drawable& l_drawable);
	void EndDraw(); // Display the changes

	// Update
	void Update();

	// Helpers
	bool IsDone();
	bool IsFullscreen();
	sf::Vector2u GetWindowSize();
	void ToggleFullscreen();

	// Getter
	sf::RenderWindow* GetRenderWindow();
private:
	// Private functions
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	// Variables
	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
};

