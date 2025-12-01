// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#pragma once
#include "raylib.h"

/**
 * @brief clase que maneja el sonido
 */
class SoundManager {
 private:
  // Sonido de click a botón
  Sound buttonClickSound;

 public:
  SoundManager();

  /**
   * @brief Inicializar sonidos
   */
  void initializeSounds();

  /**
   * @brief Desicinializar sonidos
   */
  void unloadSounds();

  /**
   * @brief Hacer sonido de click al presionar un botón
   */
  void playButtonClick();

  /**
   * @brief establecer volumen
   */
  void setVolume(float volume);
};
