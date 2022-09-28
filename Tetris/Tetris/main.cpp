#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Game.h"
using namespace std;

int main() {
	Game game;
	while (!game.GetWindow()->IsDone()) {
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
	return 0;
}