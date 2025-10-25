#pragma once
#include "Piece.h"
#include "TextEngine.h"
#include <array>
#include <cstddef>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <qt6/QtCore/QChar>
#include <qt6/QtCore/QString>

class Piece;
class QString;

   class PieceOfTable {
public:

    PieceOfTable()=delete;

    PieceOfTable                                                        (const QString&);

    PieceOfTable                                                        (const std::filesystem::path);

    void                                                                insert(size_t offset, const std::string&);

    std::string                                                         read_To_Const_Buffer(const std::filesystem::path filepath);

    void                                                                erase(size_t offset, size_t length);

    void                                                                erase(size_t offset);

    [[nodiscard]] QChar                                                 get_Char_At(size_t pos);

    QString                                                             get_Line(size_t offset, size_t length) const;

    uint32_t                                                            get_Text_Length();

    void                                                                print_Logs();

    [[nodiscard]] const std::vector<Piece>*                             get_Piece_Table() const;

    [[nodiscard]] QString*                                              get_Read_Buffer() const;

    QString                                                             &get_Add_Buffer() const;

    std::vector<Piece>                                                  get_Piece_Vector() const;

private:

    const QString                                        read_buffer;

    QString                                              add_buffer;

    std::vector<Piece>                                   piece_table;

};
