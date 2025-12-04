// Copyright [2025] Enrique Ramírez
#include "Player.hpp"

void Player::drawPlayer() {
  float scale = 0.05f;
  DrawTextureEx(playerTexture, (Vector2){x - playerTexture.width * scale / 2,
    y - playerTexture.height * scale / 2}, 0.0f, scale, WHITE);
}
