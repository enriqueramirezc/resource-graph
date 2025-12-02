// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#include "Game.hpp"

void Game::updateElements(SoundManager* soundManager) {
  // this->player.movePlayer();
  // this->ball.moveBall(soundManager);
  // this->bot.moveBot();
}

void Game::initializeGame() {
  // // Inicializacion de los elementos
  // this->player.initializePlayer();
  
  // this->ball.initializeBall();

  // this->bot.initializeBot(&this->ball);

  // this->ball.resetBallPosition();
  this->pause_button.initializeButton((char*)pause_button_path
    , pause_button_pos);
  // this->marcadorBot.init({WINDOW_WIDTH/4, 30.0f});
  // this->marcadorPly.init({(WINDOW_WIDTH/2 + WINDOW_WIDTH/4), 30.0f});

  // Dice que la escena es interactuable
  this->interactable = 0;
}

void Game::drawGameElements(SoundManager* soundManager) {
  if (interactable) updateElements(soundManager);
  // this->ball.drawBall();
  // this->player.drawPlayer();
  // this->bot.drawBot();
  this->pause_button.drawButton();

}

// Pausar juego
void Game::isGamePaused(byte& paused, SoundManager* soundManager) {
  // Si se toca botón de pausa, pausamos
  paused = (this->pause_button.isButtonBeingClicked(soundManager)) ? 1 : paused;
  // Pero también, si tocamos espacio, pausamos
  if (IsKeyDown(KEY_SPACE)) paused = 1;
}

void Game::resetMatch() {
  // this->player.resetPlayerPosition();
  // this->bot.resetBot();
  // this->ball.resetBallPosition();
  // resetScore();
}

// Poner nodos en el área de juego
void Game::drawGraph(const Graph& graph) {
  std::vector<Node> nodes = graph.getNodes();
  
  for (int i = 0; i < nodes.size(); i++) {
    Node node = nodes[i];
    Color color;
    float radius;
    
    // Colores según tipo
    if (node.getType() == 1) {  // Base
      color = BLUE;
      radius = 8.0f;
    } else if (node.getType() == 2) {  // Recurso
      color = GREEN;
      radius = 6.0f;
    } else {  // Vacío
      color = GRAY;
      radius = 4.0f;
    }
    
    // Dibujar nodo
    DrawCircle(node.getX(), node.getY(), radius, color);
    
    // ID del nodo
    DrawText(TextFormat("%d", node.getId()), 
      node.getX() - 5, node.getY() - 15, 10, WHITE);
  }
}
