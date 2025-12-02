// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#include "Window.hpp"

void Window::initializeWindow() {
  // Inicializa la ventana
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Proyecto II");

  // FPS del juego
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
  // Fondo negro en la partida
  ClearBackground(BLACK);
}
