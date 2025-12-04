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

  this->logo = LoadTexture(logo_path);
  // Inicializar Botón de "start"
  Vector2 pos = {WINDOW_WIDTH / 2.0f, (WINDOW_HEIGHT / 2.0f) + 150};
  this->start_button.initializeButton("START", pos, 100, WHITE, YELLOW);
}

// Renderizar elementos de la pantalla de bienvenida
void Home::drawHomeScreen() {
  // Fondo de la ventana (galaxia)
  float drawW = galaxy_background.width * SCALE;
  float drawH = galaxy_background.height * SCALE;
  float offsetX = (WINDOW_WIDTH  - drawW) / 2.0f;
  float offsetY = (WINDOW_HEIGHT - drawH) / 2.0f;
  DrawTextureEx(galaxy_background, {offsetX, offsetY}, 0.0f, SCALE, WHITE);

  // Primer segmento del título
  const char* perdidosTitle = "LOST";
  int perdidosTitleWidth = MeasureText(perdidosTitle, 200);
  DrawText(perdidosTitle, (WINDOW_WIDTH / 2) - (perdidosTitleWidth / 2)
  , (WINDOW_HEIGHT / 2) - 450, 200
    , GREEN);
  
  // Alien dentro de la letra "O"
  float logoScale = 0.11f;
  float logoX = (WINDOW_WIDTH / 2 - (logo.width * logoScale) / 2) - 90;
  float logoY = 97;
  DrawTextureEx(logo, {logoX, logoY}, 0.0f, logoScale, WHITE);

  // Segundo segmento del título
  const char* enLaTitle = "IN THE";
  int enLaTitleWidth = MeasureText(enLaTitle, 100);
  DrawText(enLaTitle, WINDOW_WIDTH / 2 - enLaTitleWidth / 2
    , (WINDOW_HEIGHT / 2) - 275, 100, GREEN);

  // Tercer segmento del título
  const char* galaxiaTitle = "GALAXY";
  int galaxiaTitleWidth = MeasureText(galaxiaTitle, 150);
  DrawText(galaxiaTitle, (WINDOW_WIDTH / 2) - (galaxiaTitleWidth / 2)
  , (WINDOW_HEIGHT / 2) - 180, 150, GREEN);

  // Nombre del autor
  const char* authorName = "Author: Enrique Ramírez";
  int authorNameWidth = MeasureText(authorName, 40);
  DrawText(authorName, (WINDOW_WIDTH / 2) - (authorNameWidth / 2)
  , (WINDOW_HEIGHT / 2) + 450, 40, WHITE);

  // Botón de "start"
  this->start_button.drawButton();
}

// Verificar si se ha presionado el botón start
void Home::hasGameStarted(byte& startVar, SoundManager* soundManager) {
  startVar = (this->start_button.isButtonBeingClicked(soundManager))
    ? 1 : startVar;
  if (IsKeyDown(KEY_ENTER)) startVar = 1;
}
