#include <stdlib.h>
#include "raylib.h"

#include "element.h" 

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    SetRandomSeed(1); 

    const int elementCount = 50000; // Количество элементов
    Element* elements = new Element[elementCount];

    for (int i = 0; i < elementCount; i++) {
        elements[i] = Element(screenWidth, screenHeight);
    }

    InitWindow(screenWidth, screenHeight, "raylib test"); 

    SetTargetFPS(60);

    while (!WindowShouldClose()) { 
        bool attractMode = !IsMouseButtonDown(MOUSE_RIGHT_BUTTON);
        Vector2 mousePos = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };
        for (int i = 0; i < elementCount; i++) {
            elements[i].attractTo(mousePos, 1, attractMode); // Притяжение каждого элемента к позиции курсора
            elements[i].applyFriction(0.99); // Применение трения к движению элементов
            elements[i].updatePosition(screenWidth, screenHeight); // Обновление позиции элементов
            elements[i].updateColor(mousePos); // Обновление цвета элементов в зависимости от скорости
            elements[i].render();
        }

        BeginDrawing(); 

        ClearBackground(RAYWHITE); 

        for (int i = 0; i < elementCount; i++) {
            elements[i].render();
        }

        DrawFPS(10, 10); 

        EndDrawing(); 
    }

    CloseWindow(); 

    delete[] elements;

    return 0;
}