#include "Window.h"

// Constructors / Destructors
Window::Window() {
	Setup("Tetris", { 800, 600 });
}

Window::Window(const std::string& l_title, const sf::Vector2u& l_size) {
	Setup(l_title, l_size);
}

Window::~Window() {
	Destroy();
}

// Drawing
void Window::BeginDraw() {
	m_window.clear(sf::Color::Black);
}

void Window::Draw(sf::Drawable& l_drawable) {
	m_window.draw(l_drawable);
}


void Window::EndDraw() {
	m_window.display();
}

// Update
void Window::Update() {
	sf::Event event;
	if (m_window.pollEvent(event))
		if (event.type == sf::Event::Closed)
			m_isDone = true;
		else if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::F11)
		{
			ToggleFullscreen();
		}
}

// Helpers
bool Window::IsDone(){
	return m_isDone;
}

bool Window::IsFullscreen() {
	return m_isFullscreen;
}

sf::Vector2u Window::GetWindowSize() {
	return m_windowSize;
}

void Window::ToggleFullscreen() {
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

// Getter
sf::RenderWindow* Window::GetRenderWindow(){
	return &m_window;
}

// Private functions
void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size) {
	m_isFullscreen = false;
	m_isDone = false;
	m_windowTitle = l_title;
	m_windowSize = l_size;
	Create();
}

void Window::Destroy() {
	m_window.close();
}

void Window::Create() {
	auto win_style = (m_isFullscreen == true ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, win_style);
}
