//
// Created by vovab on 07.06.2025.
//

#ifndef VEDITOR_CONSTANTS_H
#define VEDITOR_CONSTANTS_H

#pragma once

#include <cstddef>
#include <QBrush>

namespace Constants{
    // --Window & layout
    inline constexpr uint32_t WINDOW_WIDTH = 1260;
    inline constexpr uint32_t WINDOW_HEIGHT = 720;
    inline constexpr uint32_t FPS = 90;
    inline constexpr uint32_t DELAY = 1000/FPS;

    // --Numerator plugin
    inline constexpr uint32_t NUMERATION_WIDTH = 45;
    inline constexpr uint32_t NUMERATION_X_OFFSET = 125;
    inline constexpr uint32_t CODE_LINES_X_OFFSET = NUMERATION_X_OFFSET + NUMERATION_WIDTH;
    inline constexpr uint32_t CODE_LINES_Y_OFFSET = 50;
    inline constexpr uint32_t CODE_VIEWPORT_HEIGHT = WINDOW_HEIGHT - CODE_LINES_Y_OFFSET;


    // --- Brushes ---
    inline const QBrush CODE_BACKGROUND_BRUSH = QBrush(QColor(30, 31, 34));       // Main editor background
    inline const QBrush MENU_BACKGROUND_BRUSH = QBrush(QColor(56, 56, 56));       // Top menu background
    inline const QBrush LINE_NUMBER_BRUSH = QBrush(QColor(88, 88, 88));           // Line numbers background

// --- Colors ---
    inline const QColor TEXT_COLOR_WHITE_SOFT = QColor(249, 246, 238);            // Soft white text
    inline const QColor TEXT_COLOR_WHITE_PURE = QColor(255, 255, 255);            // Pure white (full intensity)
    inline const QColor TEXT_COLOR_GRAY_DARK = QColor(88, 88, 88);                // Dark gray color
}

#endif //VEDITOR_CONSTANTS_H
