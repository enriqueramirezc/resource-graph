#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "Graph.hpp"

class Player {
 private:
  int currentNode;
  Texture2D texture;
  float x, y;
  int battery;

 public:
  Player() : currentNode(0), battery(100) {}

  void initialize(const char* texturePath, int startNode) {
    this->texture = LoadTexture(texturePath);
    this->currentNode = startNode;
    this->battery = 100;
  }

  void setPosition(float px, float py) {
    this->x = px;
    this->y = py;
  }

  void draw() {
    float scale = 0.5f;
    DrawTextureEx(texture, (Vector2){x - texture.width * scale / 2, 
      y - texture.height * scale / 2}, 0.0f, scale, WHITE);
  }

  int getCurrentNode() const {
    return currentNode;
  }

  void moveToNode(int nodeId) {
    currentNode = nodeId;
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
    UnloadTexture(texture);
  }
};

#endif  // PLAYER_HPP