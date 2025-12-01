// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#include "Home.hpp"
#include "Button.hpp"
void Home::initializeHomeScreen() {
  // Se inicializa el botón que tenemos en la pantalla de bienvenida
  this->blurBG = LoadTexture(bg_path);
  this->start_button.initializeButton((char*)start_button_path
    , start_button_pos);
}

void Home::drawHomeScreen() {
  // Background
  float drawW = blurBG.width * SCALE;
  float drawH = blurBG.height * SCALE;
  float offsetX = (WINDOW_WIDTH  - drawW) / 2.0f;
  float offsetY = (WINDOW_HEIGHT - drawH) / 2.0f;
  DrawTextureEx(blurBG, {offsetX, offsetY}, 0.0f, SCALE, WHITE);

  this->start_button.drawButton();
}

void Home::hasGameStarted(byte& startVar, SoundManager* soundManager) {
  // True si se le dio click al botón
  startVar = (this->start_button.isButtonBeingClicked(soundManager)) ? 1
    : startVar;
  // True si se tocó enter
  if (IsKeyDown(KEY_ENTER)) startVar = 1;
}
