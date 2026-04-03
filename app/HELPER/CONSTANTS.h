#pragma once
#include <QString>
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
    inline constexpr uint32_t NUMERATION_X_OFFSET = 0;

    // --Code Area--
    inline constexpr uint32_t CODE_LINES_X_OFFSET = NUMERATION_X_OFFSET + NUMERATION_WIDTH;
    inline constexpr uint32_t CODE_LINES_Y_OFFSET = 50;
    inline constexpr uint32_t CODE_BOTTOM_MARGIN = 18;
    inline constexpr uint32_t CODE_VIEWPORT_HEIGHT = WINDOW_HEIGHT - CODE_LINES_Y_OFFSET;

    // --File bar plugin--
    inline constexpr uint32_t FILE_BAR_HEIGHT = 35;
    inline constexpr uint32_t FILE_BAR_X_OFFSET = CODE_LINES_X_OFFSET;
    inline constexpr uint32_t FILE_BAR_Y_OFFSET = CODE_LINES_Y_OFFSET;
    inline constexpr uint32_t FILE_BAR_TEXT_HEIGHT = 20;
    inline constexpr uint32_t FILE_BAR_TAB_WIDTH = 20;

    // ---Brushes ---
    inline const QBrush CODE_BACKGROUND_BRUSH = QBrush(QColor(30, 30, 30));       // Main editor background
    inline const QBrush FILE_BAR_BACKGROUND_BRUSH = QBrush(QColor(28, 29, 32));       // File Bar empty space
    inline const QBrush FILE_BAR_ACTIVE_TAB = QBrush(QColor((92, 92, 86)));         // File Bar active tab
    inline const QBrush FILE_BAR_INACTIVE_TAB = QBrush(QColor(35, 35, 35));        // File Bar inactive tab
    inline const QBrush MENU_BACKGROUND_BRUSH = CODE_BACKGROUND_BRUSH;       // Top menu background
    inline const QBrush LINE_NUMBER_BRUSH = QBrush(QColor(35, 35, 35));           // Line numbers background

    // --- Pens ---
    inline const QPen LINES_PEN =  QPen(LINE_NUMBER_BRUSH, 1, Qt::SolidLine);

    // --- Colors ---
    inline const QColor TEXT_COLOR_WHITE_PURE = QColor(212, 212, 212);            
    inline const QColor TEXT_SOFT_YELLOW = QColor(235, 219, 178);
    inline const QColor TEXT_GRAY_MID = QColor(88, 83, 85);

}
