//
// SPDX-License-Identifier: MIT
// /file  : File.h
// Last modified: 2025-08-28 19:06
//

#pragma once
#include <memory>
#include <filesystem>
#include "../text/TextEngine.h"

class TextEngine;

class File {
public:

    File                                                 (const std::filesystem::path path);

    [[nodiscard]] size_t                                 file_Name_Length() const;

    [[nodiscard]] std::string                            file_Name() const;

    [[nodiscard]] PieceOfTable*                          text_Data_Structure() const;

    [[nodiscard]] TextEngine*                            text_Engine() const;

private:

    std::string                         name;

    std::unique_ptr<PieceOfTable>       text_data_structure;

    std::unique_ptr<TextEngine>         text_engine;


};
