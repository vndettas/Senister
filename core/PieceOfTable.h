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
#include "Piece.h"


class PieceOfTable {
public:

    [[nodiscard]] QString* getReadBuffer() const;

    QString &getAddBuffer() const;

    std::string readToBuffer(const std::string& filepath);

    PieceOfTable(const std::string& filepath);

    [[nodiscard]] const  std::vector<Piece>* getPieceTable() const;


private:

    const QString read_buffer;

     QString add_buffer;

    std::vector<Piece> piece_table;

};


#endif //VEDITOR_PIECEOFTABLE_H
