// Copyright [2025] Enrique Ramírez
#include "Defeat.hpp"

void Defeat::initializeDefeatMenu() {
  Vector2 pos_restart = {WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f + 200};
  this->restart_button.initializeButton("RESTART", pos_restart, 80, WHITE, YELLOW);
  Vector2 pos_home = {WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f + 80};
  this->home_button.initializeButton("HOME", pos_home, 80, WHITE, YELLOW);
}

void Defeat::drawDefeatMenu() {
  const char* defeatTitle = "GAME OVER";
  int defeatTitleWidth = MeasureText(defeatTitle, 130);
  DrawText(defeatTitle, WINDOW_WIDTH / 2 - defeatTitleWidth / 2, (WINDOW_HEIGHT / 2) - 400, 130
    , RED);

  const char* optionsMessage = "Options:";
  int optionsMessageWidth = MeasureText(optionsMessage, 100);
  DrawText(optionsMessage, (WINDOW_WIDTH / 2) - (optionsMessageWidth / 2)
  , (WINDOW_HEIGHT / 2) - 100, 100, YELLOW);

  // Interfaz de usuario
  this->home_button.drawButton();
  this->restart_button.drawButton();
}

void Defeat::gameResumed(byte& resumeVar, SoundManager* soundManager) {
  resumeVar = (this->restart_button.isButtonBeingClicked(soundManager))? 1
    : resumeVar;
}

void Defeat::goHome(byte& goHomeVar, SoundManager* soundManager) {
  goHomeVar = (this->home_button.isButtonBeingClicked(soundManager))? 1
    : goHomeVar;
}
