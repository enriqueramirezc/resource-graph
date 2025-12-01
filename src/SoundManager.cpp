// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#include "SoundManager.hpp"
#include <stdio.h>

SoundManager::SoundManager() {}

void SoundManager::initializeSounds() {
  // Inicializar audio
  InitAudioDevice();

  // Cargar archivos de sonido
  buttonClickSound = LoadSound("assets/sound/clickButton.wav");
}

void SoundManager::unloadSounds() {
  UnloadSound(buttonClickSound);
  CloseAudioDevice();
}

void SoundManager::playButtonClick() {
  PlaySound(buttonClickSound);
}


void SoundManager::setVolume(float volume) {
  SetSoundVolume(buttonClickSound, volume);
}
