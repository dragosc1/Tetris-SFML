#include "Game.h"

Game::Game() : m_window("Tetris", sf::Vector2u(800, 600)) { }

Game::~Game() { }

sf::Time Game::GetElapsed() { return m_elapsed; }

void Game::RestartClock() { m_elapsed = m_clock.restart(); }

void Game::HandleInput() { }

void Game::Update() { m_window.Update(); }

void Game::Render() {
    m_window.BeginDraw();
    m_window.EndDraw();
}

Window* Game::GetWindow() { return &m_window; }