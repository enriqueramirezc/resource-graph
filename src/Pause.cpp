// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#include "Pause.hpp"

void Pause::initializePauseMenu() {
  Vector2 pos_home = {WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f + 80};
  this->home_button.initializeButton("HOME", pos_home, 80, WHITE, YELLOW);

  Vector2 pos_resume = {WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f + 200};
  this->resume_button.initializeButton("RESUME", pos_resume, 80, WHITE, YELLOW);
}

void Pause::drawPauseMenu() {
  const char* pauseMessage = "Game Paused";
  int pauseMessageWidth = MeasureText(pauseMessage, 130);
  DrawText(pauseMessage, (WINDOW_WIDTH / 2) - (pauseMessageWidth / 2)
  , (WINDOW_HEIGHT / 2) - 400, 130, YELLOW);

  const char* optionsMessage = "Options:";
  int optionsMessageWidth = MeasureText(optionsMessage, 100);
  DrawText(optionsMessage, (WINDOW_WIDTH / 2) - (optionsMessageWidth / 2)
  , (WINDOW_HEIGHT / 2) - 100, 100, YELLOW);

  // Interfaz de usuario
  this->home_button.drawButton();
  this->resume_button.drawButton();
}

void Pause::gameResumed(byte& resumeVar, SoundManager* soundManager) {
  resumeVar = (this->resume_button.isButtonBeingClicked(soundManager))? 1
    : resumeVar;
}

void Pause::goHome(byte& goHomeVar, SoundManager* soundManager) {
  goHomeVar = (this->home_button.isButtonBeingClicked(soundManager))? 1
    : goHomeVar;
}
