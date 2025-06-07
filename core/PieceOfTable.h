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
#include "Editor.h"
#include "HELPER/CONSTANTS.h"


enum class buffer {
    add_buffer, read_only_buffer
};

class PieceOfTable {
public:
       struct Piece {
        public:

            size_t offset;

            size_t length;

            buffer buffer_type;

            Piece(size_t offset, size_t length, buffer bufferType);


        };
public:

    [[nodiscard]] QString* getReadBuffer() const;

    QString &getAddBuffer() const;

    std::string readToBuffer(const std::string& filepath);

    QString &getTextRange(size_t offset, size_t length);

    PieceOfTable(const std::string& filepath);

    [[nodiscard]] const  std::vector<Piece>* getPieceTable() const;

private:

    const QString read_buffer;

     QString add_buffer;

    std::vector<Piece> piece_table;

};


#endif //VEDITOR_PIECEOFTABLE_H
