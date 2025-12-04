// Copyright [2025] Enrique Ramírez
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"

class Player {
 private:
  const char* player_path = "assets/img/player.jpg";
  int currentNode;
  Texture2D playerTexture;
  float x, y;
  int battery;

 public:
  void initializePlayer() {
    this->currentNode = 0;
    this->x = 0;
    this->y = 0;
    this->battery = 100;
    this->playerTexture = LoadTexture(player_path);
    this->battery = 100;
  }

  void setPlayerPosition(float px, float py) {
    this->x = px;
    this->y = py;
  }

  void updatePlayer(int edgeWeight, int i, int x, int y) {
    consumeBattery(edgeWeight);
    setCurrentNode(i);
    setPlayerPosition(x, y);
    if (currentNode == 0) {
      rechargeBattery();
    }
  }

  void drawPlayer();

  void setCurrentNode(int nodeId) {
    currentNode = nodeId;
  }

  int getCurrentNode() const {
    return currentNode;
  }

  int getBattery() const {
    return battery;
  }

  void consumeBattery(int amount) {
    battery -= amount;
    if (battery < 0) battery = 0;
  }

  void rechargeBattery() {
    battery = 100;
  }

  void rechargeAtMachine() {
    if (battery < 60) {
      battery = 60;
    }
  }

  void unload() {
    UnloadTexture(playerTexture);
  }
};

#endif  // PLAYER_HPP
