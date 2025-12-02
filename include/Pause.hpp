// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#pragma once
#include "Shared.hpp"
#include "Button.hpp"

/**
 * @brief Clase encargada del manejo del menú de juego
 */
class Pause {
 private:
  // Botón de regresar a partida
  Button resume_button;
  // Botón de regresar a home
  Button home_button;

 public:
  /**
   * @brief Inicializa los elementos de la clase, carga sus texturas y
   * posiciones.
   */
  void initializePauseMenu();

  /**
   * @brief Rederiza el menú en pantalla
   */
  void drawPauseMenu();

  /**
   * @brief Se regresa a la partida
   */
  void gameResumed(byte&, SoundManager* soundManager);

  /**
   * @brief Se regresa al inicio
   */
  void goHome(byte&, SoundManager* soundManager);
};
