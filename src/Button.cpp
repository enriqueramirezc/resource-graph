// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#include "Button.hpp"

// Inicializar botón
void Button::initializeButton(const char* txt, Vector2 pos, int size, Color col
  , Color hover) {
  this->text = txt;
  this->position = pos;
  this->fontSize = size;
  this->color = col;
  this->hoverColor = hover;
}

// Dibujar botón en pantalla
void Button::drawButton() {
  int textWidth = MeasureText(text, fontSize);
  Vector2 drawPos = {position.x - textWidth/2.0f, position.y};
  
  // Botón cambia de color si el mouse está encima de él
  Color currentColor = isMouseAboveButton() ? hoverColor : color;
  DrawText(text, drawPos.x, drawPos.y, fontSize, currentColor);
}

// Verificar si se está encima del botón
byte Button::isMouseAboveButton() {
  int textWidth = MeasureText(text, fontSize);
  Rectangle bounds = {
    position.x - textWidth/2.0f,
    position.y,
    (float)textWidth,
    (float)fontSize
  };
  Vector2 mousePos = GetMousePosition();
  return CheckCollisionPointRec(mousePos, bounds);
}

// Verificar si se está tocando el botón
byte Button::isButtonBeingClicked(SoundManager* soundManager) {
  if (isMouseAboveButton() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    if (soundManager) {
      soundManager->playButtonClick();
    }
    return 1;
  }
  return 0;
}
