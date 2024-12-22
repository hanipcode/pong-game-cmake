/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

For a C++ project simply rename the file to .cpp and re-run the build script

-- Copyright (c) 2020-2024 Jeffery Myers
--
--This software is provided "as-is", without any express or implied warranty. In
no event
--will the authors be held liable for any damages arising from the use of this
software.

--Permission is granted to anyone to use this software for any purpose,
including commercial
--applications, and to alter it and redistribute it freely, subject to the
following restrictions:

--  1. The origin of this software must not be misrepresented; you must not
claim that you
--  wrote the original software. If you use this software in a product, an
acknowledgment
--  in the product documentation would be appreciated but is not required.
--
--  2. Altered source versions must be plainly marked as such, and must not be
misrepresented
--  as being the original software.
--
--  3. This notice may not be removed or altered from any source distribution.

*/

#include "raylib.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const float WORLD_WIDTH = 640;
const float WORLD_HEIGHT = 360;

typedef struct Point {
  float x;
  float y;
} Point;

typedef struct Dimension {
  float width;
  float height;
} Dimension;
typedef struct PlayerBar {
  Point position;
  Dimension size;
} PlayerBar;

float getScale() {
  return fminf(GetRenderWidth() / WORLD_WIDTH,
               GetRenderHeight() / WORLD_HEIGHT);
};

PlayerBar *createPlayerBar() {
  PlayerBar *pb = malloc(sizeof(PlayerBar));
  if (pb == NULL) {
    printf(" Memory allocation failed \n");
    return NULL;
  }
  pb->size = (Dimension){100, 15};
  pb->position = (Point){(WORLD_WIDTH - 100) / 2, WORLD_HEIGHT - 25};

  return pb;
}

int main() {
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE);

  InitWindow(WORLD_WIDTH, WORLD_HEIGHT, "Hello new world");
  SetWindowPosition(0, 0);

  PlayerBar *pb = createPlayerBar();

  while (!WindowShouldClose()) // run the loop untill the user presses ESCAPE or
                               // presses the Close button on the window
  {
    BeginDrawing();

    ClearBackground(BLACK);

    float scale = getScale();
    float offsetX = (GetRenderWidth() - WORLD_WIDTH * scale) / 2.0f;
    float offsetY = (GetRenderHeight() - WORLD_HEIGHT * scale) / 2.0f;

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
      pb->position.x = fmax(pb->position.x - 5, 0);
    }

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
      pb->position.x = fmin(pb->position.x + 5, WORLD_WIDTH - pb->size.width);
    }

    DrawRectangle(offsetX, offsetY, WORLD_WIDTH * scale, WORLD_HEIGHT * scale,
                  GRAY);
    DrawRectangleLines(offsetX + pb->position.x * scale,
                       offsetY + pb->position.y * scale, pb->size.width * scale,
                       pb->size.height * scale, WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
