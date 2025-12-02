// Copyright [2025] Enrique Ramírez
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "raylib.h"
#include "SoundManager.hpp"
#include <cstdint>

typedef std::uint8_t byte;

/**
 * @brief Clase que representa un botón de texto dentro del juego.
 */
class Button {
 private:
  const char* text;  // Texto del botón
  Vector2 position;  // Posición del botón
  int fontSize;  // Tamaño de letra del texto del botón
  Color color;  // Color del botón
  Color hoverColor;  // Color del botón cuando el mouse está encima de él

 public:
  // Constructor
  Button() : text(""), fontSize(20), color(WHITE), hoverColor(YELLOW) {}

  /**
   * @brief Método que inicializa un botón
   */
  void initializeButton(const char* txt, Vector2 pos, int size, Color col
    , Color hover);

  /**
   * @brief Método para dibujar un botón
   */
  void drawButton();

  /**
   * @brief método que verifica si el cursor se encuentra sobre el botón
   */
  byte isMouseAboveButton();

  /**
   * @brief Método que verifica si el botón está siendo presionado
   */
  byte isButtonBeingClicked(SoundManager* soundManager);
};  // class Button
#endif  // BUTTON_HPP
