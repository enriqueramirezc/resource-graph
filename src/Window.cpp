// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#include "Window.hpp"

void Window::initializeWindow() {
  // Inicializa la ventana
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Proyecto II");

  // Carga la textura del game_background
  this->game_background = LoadTexture(game_background_path);

  // Establece los FPS
  SetTargetFPS(60);
}


void Window::beginWindowDraw() {
  BeginDrawing();
  drawWindowBackground();
}

void Window::endWindowDraw() {
  EndDrawing();
}

void Window::drawWindowBackground() {
  float drawW = game_background.width * SCALE;
  float drawH = game_background.height * SCALE;
  float offsetX = (WINDOW_WIDTH  - drawW) / 2.0f;
  float offsetY = (WINDOW_HEIGHT - drawH) / 2.0f;
  DrawTextureEx(game_background, {offsetX, offsetY}, 0.0f, SCALE, WHITE);
}
