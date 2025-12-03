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
  Player() : currentNode(0), battery(100), x(0), y(0) {}

  void initializePlayer() {
    this->playerTexture = LoadTexture(player_path);
    this->battery = 100;
  }

  void setPlayerPosition(float px, float py) {
    this->x = px;
    this->y = py;
  }

  void updatePlayer() {

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

  void unload() {
    UnloadTexture(playerTexture);
  }
};

#endif  // PLAYER_HPP