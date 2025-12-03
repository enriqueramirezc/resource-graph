// Copyright [2025] Enrique Ramírez
#pragma once
#include "Shared.hpp"
#include "Button.hpp"

/**
 * @brief Clase encargada de mostrar la pantalla de derrota
 */
class Defeat {
 private:
  // Botón de reiniciar la partida
  Button restart_button;
  // Botón de regresar a home
  Button home_button;

 public:
  /**
   * @brief Inicializa los elementos de la clase, carga sus texturas y
   * posiciones.
   */
  void initializeDefeatMenu();

  /**
   * @brief Rederiza el menú en pantalla
   */
  void drawDefeatMenu();

  /**
   * @brief Se regresa a la partida
   */
  void gameResumed(byte&, SoundManager* soundManager);

  /**
   * @brief Se regresa al inicio
   */
  void goHome(byte&, SoundManager* soundManager);
};
