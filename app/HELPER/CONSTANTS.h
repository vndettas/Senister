//
// SPDX-License-Identifier: MIT
// /file  : CONSTANTS.h
// Last modified: 2025-08-29 01:50
//

#pragma once
#include <cstddef>
#include <QBrush>
#include <QPen>

namespace Constants {


    // --Window & layout--
    inline constexpr uint32_t WINDOW_WIDTH = 1260;
    inline constexpr uint32_t WINDOW_HEIGHT = 720;
    inline constexpr uint32_t FPS = 120;
    inline constexpr uint32_t DELAY = 1000/FPS;

    // --Numerator plugin--
    inline constexpr uint32_t NUMERATION_WIDTH = 45;
    inline constexpr uint32_t NUMERATION_X_OFFSET = 125;

    // --Code Area--
    inline constexpr uint32_t CODE_LINES_X_OFFSET = NUMERATION_X_OFFSET + NUMERATION_WIDTH;
    inline constexpr uint32_t CODE_LINES_Y_OFFSET = 50;
    inline constexpr uint32_t CODE_VIEWPORT_HEIGHT = WINDOW_HEIGHT - CODE_LINES_Y_OFFSET;

    // --File bar plugin--
    inline constexpr uint32_t FILE_BAR_HEIGHT = 35;
    inline constexpr uint32_t FILE_BAR_X_OFFSET = CODE_LINES_X_OFFSET;
    inline constexpr uint32_t FILE_BAR_Y_OFFSET = CODE_LINES_Y_OFFSET;
    inline constexpr uint32_t FILE_BAR_TEXT_HEIGHT = 20;
    inline constexpr uint32_t FILE_BAR_TAB_WIDTH = 20;

    // ---Brushes ---
    inline const QBrush CODE_BACKGROUND_BRUSH = QBrush(QColor(30, 31, 34));       // Main editor background
    inline const QBrush FILE_BAR_BACKGROUND_BRUSH = QBrush(QColor(28, 29, 32));       // File Bar empty space
    inline const QBrush FILE_BAR_ACTIVE_TAB = QBrush(QColor((92, 92, 86)));         // File Bar active tab
    inline const QBrush FILE_BAR_INACTIVE_TAB = QBrush(QColor(35, 35, 35));        // File Bar inactive tab
    inline const QBrush MENU_BACKGROUND_BRUSH = QBrush(QColor(56, 56, 56));       // Top menu background
    inline const QBrush LINE_NUMBER_BRUSH = QBrush(QColor(88, 88, 88));           // Line numbers background

    // --- Pens ---
    inline const QPen LINES_PEN =  QPen(LINE_NUMBER_BRUSH, 1, Qt::SolidLine);

    // --- Colors ---
    inline const QColor TEXT_COLOR_WHITE_SOFT = QColor(249, 246, 238);            // Soft white text
    inline const QColor TEXT_COLOR_WHITE_PURE = QColor(255, 255, 255);            // Pure white (full intensity)
    inline const QColor TEXT_COLOR_GRAY_DARK = QColor(88, 88, 88);                // Dark gray color


}
