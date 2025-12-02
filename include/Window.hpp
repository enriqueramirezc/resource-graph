// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#pragma once
#include <iostream>
#include "Shared.hpp"

/**
 * @brief Clase responsable de generar la ventana de juego con su respectivo
 * fondo negro y fps.
 */
class Window {
 private:
  /**
   * @brief Dibuja el fondo de la ventana
   */
  void drawWindowBackground();

 public:
  /**
   * @brief Inicializa la ventana con un ancho, alto, fondo, FPS y nombre
   * establecidos.
  */
  void initializeWindow();
  void beginWindowDraw();

  /**
   * @brief terminar de mostrar un frame.
   */
  void endWindowDraw();
  void killWindow() {
    CloseWindow();
  }
};
