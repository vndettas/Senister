//
// Created by vovab on 13.03.2025.
//

#ifndef VEDITOR_PIECEOFTABLE_H
#define VEDITOR_PIECEOFTABLE_H


#include <array>
#include <string>
#include <fstream>
#include <QString>
#include <iostream>



enum class buffer{
    add_buffer, read_only_buffer
};

struct Piece {
public:

    size_t offset;

    size_t length;

    buffer buffer_type;

    Piece(size_t offset, size_t length, buffer bufferType);

};

    class PieceOfTable {
public:

    [[nodiscard]] QChar get_Char_At(size_t pos);

    [[nodiscard]] QString* get_Read_Buffer() const;

    size_t get_Text_Length();

    QString get_Line(size_t offset, size_t length);

    QString &get_Add_Buffer() const;

    std::string read_To_Buffer(const std::string& filepath);

    QString &get_Text_Range(size_t offset, size_t length);

    void insert(size_t offset, const std::string&);

    void erase(size_t offset, size_t length);

    PieceOfTable(const std::string& filepath);

    [[nodiscard]] const  std::vector<Piece>* get_Piece_Table() const;

private:

    const QString read_buffer;

     QString add_buffer;

    std::vector<Piece> piece_table;

};


#endif //VEDITOR_PIECEOFTABLE_H
