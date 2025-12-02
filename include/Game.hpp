// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#pragma once
#include "Shared.hpp"
#include "Button.hpp"
#include "Graph.hpp"

/**
 * @brief Clase responsable de la partida en juego.
 */
class Game {
 private:
  // Indicador de si un elemento es interactuable
  std::uint8_t interactable;

  void updateElements();

 public:
  /**
   * @brief Inicializa los elementos de la clase,
   * carga sus texturas y posiciones.
   */
  void initializeGame();

  /**
   * @brief Rederiza los elementos de la partida en pantalla.
   */
  void drawGameElements();

  /**
   * @brief Cambia el estado del juego,
   * si la varible que cambia esta en 0
   * entonces los componentes se vuelven
   * no interactuales.
   */
  void setInteractable() {
    interactable = 1;
  }

  void setNotInteractable() {
    interactable = 0;
  }

  /**
   * @brief Método encargado de verificar si la partida se encuentra pausada.
   */
  void isGamePaused(byte& paused);

  /**
   * @brief Restablece el progreso de la partida.
   */
  void resetMatch();

  void drawGraph(const Graph& graph);
};
