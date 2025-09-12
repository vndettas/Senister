//
// SPDX-License-Identifier: MIT
// /file  : PieceOfTable.h
// Last modified: 2025-08-19 11:59
//

#pragma once
#include "Piece.h"
#include <array>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <QString>

class Piece;


   class PieceOfTable {
public:

    PieceOfTable()=delete;

    PieceOfTable                                                        (const std::filesystem::path);

    void                                                                insert(size_t offset, const std::string&);

    void                                                                delete_Char(size_t offset);

    std::string                                                         read_To_Const_Buffer(const std::filesystem::path filepath);

    void                                                                erase(size_t offset, size_t length);

    [[nodiscard]] QChar                                                 get_Char_At(size_t pos);

    QString                                                             get_Line(size_t offset, size_t length) const;

    uint32_t                                                            get_Text_Length();

    void                                                                print_Logs_Piece_Table();

    [[nodiscard]] const std::vector<Piece>*                             get_Piece_Table() const;

    [[nodiscard]] QString*                                              get_Read_Buffer() const;

    QString                                                             &get_Add_Buffer() const;

private:

    const QString                                        read_buffer;

    QString                                              add_buffer;

    std::vector<Piece>                                   piece_table;

};
