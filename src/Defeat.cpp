// Copyright [2025] Enrique Ramírez
#include "Defeat.hpp"

void Defeat::initializeDefeatMenu() {
  Vector2 pos_home = {WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f - 100};
  this->home_button.initializeButton("HOME", pos_home, 80, WHITE, YELLOW);

  Vector2 pos_resume = {WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f + 30};
  this->restart_button.initializeButton("RESTART", pos_resume, 80, WHITE, YELLOW);
}

void Defeat::drawDefeatMenu() {
  const char* defeatTitle = "YOU'VE LOST";
  int defeatTitleWidth = MeasureText(defeatTitle, 30);
  DrawText(defeatTitle, WINDOW_WIDTH / 4 - defeatTitleWidth / 2, (WINDOW_HEIGHT / 2) - 300, 100
    , RED);
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
