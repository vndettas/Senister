//
// Created by vovab on 24.03.2025.
//

#ifndef VEDITOR_PIECE_H
#define VEDITOR_PIECE_H


#include <cstddef>

enum class buffer {
    add_buffer, read_only_buffer
};

class Piece {

public:

    size_t offset;

    size_t length;

    buffer buffer_type;

    Piece(size_t offset, size_t length, buffer bufferType);


};


#endif //VEDITOR_PIECE_H
