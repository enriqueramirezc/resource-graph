// Copyright [2025] Enrique Ramírez
#pragma once
#include "Shared.hpp"
#include "Button.hpp"
#include "Graph.hpp"
#include "Player.hpp"
#include "Pipe.hpp"
#include <vector>

/**
 * @brief Clase responsable de la partida en juego.
 */
class Game {
 private:
  Player player;
  Pipe pipe;

  float scale = 1.2f;
  float offsetX = 30.0f;
  float offsetY = 120.0f;
  std::uint8_t interactable;

  int plyResources;
  std::vector<bool> exploredNodes;
  int engineCost = 3000;

  int selectedResourceNode = -1;

  void updateElements(Graph& graph);

 public:
  /**
   * @brief Inicializa los elementos de la clase,
   * carga sus texturas y posiciones.
   */
  void initializeGame(Graph& graph);

  /**
   * @brief Rederiza los elementos de la partida en pantalla.
   */
  void drawGameElements(Graph& graph);

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
   * @brief Verifica si el jugador ha perdido.
   */
  void checkDefeat(byte& defeated);

  /**
   * @brief Restablece el progreso de la partida.
   */
  void resetMatch(Graph& graph);

  /**
   * @brief Verificar condición de victoria
   */
  bool canBuyEngine() const {
    return plyResources >= engineCost;
  }
};
