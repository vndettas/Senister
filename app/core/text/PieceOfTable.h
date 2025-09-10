// 
// SPDX-License-Identifier: MIT
// /file  : PieceOfTable.h
// Last modified: 2025-08-19 11:59
// 

#pragma once
#include <array>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <QString>


enum class buffer{
    add_buffer, read_only_buffer
    
};

inline std::ostream& operator<<(std::ostream& os, buffer b) {
    switch (b) {
        case buffer::add_buffer: return os << "add_buffer";
        case buffer::read_only_buffer: return os << "read_only_buffer";
        default: return os << "unknown";
    }
}


struct Piece {
public:

    void shrink_Front();

    void shrink_Front(size_t length);

    void shrink_Back();

    void shrink_Back(size_t length);

    void set_Length(size_t length);

    size_t offset;

    size_t length;

    buffer buffer_type;

    Piece(size_t offset, size_t length, buffer bufferType);

};

    class PieceOfTable {
public:

    PieceOfTable(const std::filesystem::path);

    [[nodiscard]] QChar get_Char_At(size_t pos);

    uint32_t get_Text_Length();

    QString get_Line(size_t offset, size_t length) const;

    std::string read_To_Const_Buffer(const std::filesystem::path filepath);

    void print_Logs_Piece_Table();

    void insert(size_t offset, const std::string&);

    void delete_Char(size_t offset);

    void erase(size_t offset, size_t length);

        //Getters
    [[nodiscard]] const  std::vector<Piece>* get_Piece_Table() const;

    [[nodiscard]] QString* get_Read_Buffer() const;

    QString &get_Add_Buffer() const;

private:

    const QString read_buffer;

     QString add_buffer;

    std::vector<Piece> piece_table;

};


