#pragma once

#include "raylib.h"
#include <random>


inline std::random_device rd;
inline std::mt19937 gen(rd());
inline int number = std::uniform_int_distribution<int>(0, 3)(gen);

inline int width = 800;
inline int height = 450;

inline Texture2D bird;
inline Texture2D bird_up;
inline Texture2D bird_down;
inline Texture2D bird_right;
inline Texture2D bird_left;
inline Texture2D cable;

const float gravity = 500.0f;
const float jumpForce = -250.0f;
const float groundY = 400.0f;
const float ceilingY = 0.0f;

float velocityY = 0.0f;

bool lose = false;
bool paused = false;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void jump()
{
    velocityY = jumpForce;
    number = std::uniform_int_distribution<int>(0, 3)(gen);

    if (lose == false) {
        if (number == 0) {
            bird = bird_up;
        } else if (number == 1) {
            bird = bird_down;
        } else if (number == 2) {
            bird = bird_right;
        } else {
            bird = bird_left;
        }
    }
}

#endif
