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
  // Ruta al fondo de la pantalla de inicio
  const char* bg_path = "assets/img/bg_space_800x600.png";

  // Logo (gato alien)
  const char* logo_path = "assets/img/alien.jpg";

  // Botón de "start" de la partida
  Button start_button;

  // Textura del alien que aparece en el logo
  Texture2D logo;

  // Textura de galaxia para el fondo del home screen
  Texture2D galaxy_background;

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
   * @brief Verifica si se dio click al botón de inicio
   */
  void hasGameStarted(byte&, SoundManager* soundManager);

  void unloadTextures() {
    UnloadTexture(galaxy_background);
    UnloadTexture(logo);
  }
};
