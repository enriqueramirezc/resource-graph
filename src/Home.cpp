// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#include "Home.hpp"

// Inicializar elementos de pantalla de bienvenida.
void Home::initializeHomeScreen() {
  // Cargar textura de galaxia
  this->galaxy_background = LoadTexture(bg_path);

  // Inicializar Botón de "start"
  Vector2 pos = {WINDOW_WIDTH / 2.0f, (WINDOW_HEIGHT / 2.0f) + 150};
  this->start_button.initializeButton("START", pos, 100, WHITE, YELLOW);
}

// Renderizar elementos de la pantalla de bienvenida
void Home::drawHomeScreen() {
  float drawW = galaxy_background.width * SCALE;
  float drawH = galaxy_background.height * SCALE;
  float offsetX = (WINDOW_WIDTH  - drawW) / 2.0f;
  float offsetY = (WINDOW_HEIGHT - drawH) / 2.0f;
  DrawTextureEx(galaxy_background, {offsetX, offsetY}, 0.0f, SCALE, WHITE);

  const char* perdidosTitle = "PERDIDOS";
  int perdidosTitleWidth = MeasureText(perdidosTitle, 150);
  DrawText(perdidosTitle, (WINDOW_WIDTH / 2) - (perdidosTitleWidth / 2)
  , (WINDOW_HEIGHT / 2) - 400, 150
    , YELLOW);
  
  const char* naFacultade = "EN LA FACULTAD";
  int naFacultadeWidth = MeasureText(naFacultade, 88);
  DrawText(naFacultade, WINDOW_WIDTH / 2 - naFacultadeWidth / 2
    , (WINDOW_HEIGHT / 2) - 250, 88, YELLOW);

  const char* deLetras = "DE LETRAS";
  int deLetrasWidth = MeasureText(deLetras, 130);
  DrawText(deLetras, (WINDOW_WIDTH / 2) - (deLetrasWidth / 2)
  , (WINDOW_HEIGHT / 2) - 150, 130, RED);

  this->start_button.drawButton();
}

// Verificar si se ha presionado el botón start
void Home::hasGameStarted(byte& startVar, SoundManager* soundManager) {
  startVar = (this->start_button.isButtonBeingClicked(soundManager))
    ? 1 : startVar;
  if (IsKeyDown(KEY_ENTER)) startVar = 1;
}
