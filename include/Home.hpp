// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#pragma once
#include "Button.hpp"
#include "Shared.hpp"

/**
 * @brief Clase que representa la pantalla de bienvenida del juego
 */
class Home {
 private:
  // Ruta a los elementos visuales de la pantalla de inicio
  const char* start_button_path = "assets/img/start_button.png";
  const char* bg_path = "assets/img/bg_space_800x600.png";

  Button start_button;  // Botón de inicio
  Texture2D blurBG;

 public:
  /**
   * @brief Inicializar pantalla de inicio
   */
  void initializeHomeScreen();

  /**
   * @brief Renderizar pantalla de bienvenida
   */
  void drawHomeScreen();

  /**
   * @brief Para ir a settings
   */
  void gameSettings(byte& settings, SoundManager* soundManager);

  /**
   * @brief Verifica si se dio click al botón de inicio
   */
  void hasGameStarted(byte&, SoundManager* soundManager);
};
