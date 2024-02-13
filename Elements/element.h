#include <stdlib.h>
#include <math.h>
#include "raylib.h"

class Element {
private:
    Vector2 position; // ������� ��������
    Vector2 velocity; // �������� ��������
    Color hue; // ���� ��������
    float minDistance = 0.0f; // ����������� ���������� ��� �������� ������������
    float maxDistance = 500.0f; // ������������ ���������� ��� �������� ������������

    // ���������� ���������� �� ������� ������� �������� �� ��������� �������
    float calculateDistance(Vector2 targetPosition);
    // ���������� ��������������� ������ ����������� �� ������� ������� �������� �� ��������� �������
    Vector2 calculateDirection(Vector2 targetPosition);

public:
    Element();
    // ����������� ��� ������������� �������� � ���������� �������� � ���������
    Element(int screenWidth, int screenHeight);
    // ����������� ��� ������������� �������� � ��������� ��������, ��������� � ������
    Element(Vector2 position, Vector2 velocity, Color hue);

    // ����������� ������� � ��������� ������� � �������� ����������
    void attractTo(Vector2 targetPosition, float force, bool attractMode);
    // ��������� ������ � �������� ��������
    void applyFriction(float coefficient);
    // ���������� �������, �������� ������� ������
    void updatePosition(int screenWidth, int screenHeight);
    // ������ ������� �� ������
    void render();
    void updateColor(Vector2 cursorPosition);
};
Element::Element() : position({ 0, 0 }), velocity({ 0, 0 }), hue(BLACK) {
}
Element::Element(int screenWidth, int screenHeight) {
    position.x = GetRandomValue(0, screenWidth - 1);
    position.y = GetRandomValue(0, screenHeight - 1);
    velocity.x = GetRandomValue(-100, 100) / 100.0f;
    velocity.y = GetRandomValue(-100, 100) / 100.0f;
    hue = Color{ 0, 0, 0, 100 };
}

Element::Element(Vector2 position, Vector2 velocity, Color hue) : position(position), velocity(velocity), hue(hue) {}

float Element::calculateDistance(Vector2 targetPosition) {
    float dx = position.x - targetPosition.x;
    float dy = position.y - targetPosition.y;
    return sqrt((dx * dx) + (dy * dy));
}

Vector2 Element::calculateDirection(Vector2 targetPosition) {
    float distance = calculateDistance(targetPosition);
    if (distance == 0.0f) distance = 1.0f;
    float dx = position.x - targetPosition.x;
    float dy = position.y - targetPosition.y;
    return Vector2{ dx / distance, dy / distance };
}

void Element::attractTo(Vector2 targetPosition, float force, bool attractMode) {
    Vector2 direction = calculateDirection(targetPosition);
    float distance = fmax(calculateDistance(targetPosition), 1.0f); // �������� ������� �� ����

    if (!attractMode) {
        // ����������
        velocity.x += direction.x * force / distance;
        velocity.y += direction.y * force / distance;
    }
    else {
        // ������������
        velocity.x -= direction.x * force / distance;
        velocity.y -= direction.y * force / distance;
    }
}


void Element::applyFriction(float coefficient) {
    velocity.x *= coefficient;
    velocity.y *= coefficient;
}

void Element::updateColor(Vector2 cursorPosition) {
    float distance = calculateDistance(cursorPosition);

    // ������������ ���������� ��� ��������� �������� �� 0 �� 1
    float normalizedDistance = (distance - minDistance) / (maxDistance - minDistance);
    normalizedDistance = fmax(0.0f, fmin(normalizedDistance, 1.0f)); // ��������, ��� �������� ��������� � �������� [0, 1]

    // ������������ ����� ������� (������ � �������) � ������� (������ �� �������)
    hue = Color{
        static_cast<unsigned char>(normalizedDistance * 255), // �������
        0,
        static_cast<unsigned char>((1.0f - normalizedDistance) * 255), // �����
        255
    };
}


void Element::updatePosition(int screenWidth, int screenHeight) {
    position.x += velocity.x;
    position.y += velocity.y;

    // ��������� ������ �� ������� ������
    if (position.x < 0) position.x += screenWidth;
    if (position.x >= screenWidth) position.x -= screenWidth;
    if (position.y < 0) position.y += screenHeight;
    if (position.y >= screenHeight) position.y -= screenHeight;
}

void Element::render() {
    DrawPixelV(position, hue);
}