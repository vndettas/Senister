#pragma once
#include <string>
#include <iostream>

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


class Piece {
public:

    Piece()=delete;
  
    Piece                                            (size_t offset, size_t length, buffer bufferType);

    void                                             shrink_Front();

    void                                             shrink_Front(size_t length);

    void                                             shrink_Back();

    void                                             shrink_Back(size_t length);

    void                                             set_Length(size_t length);

    size_t                           offset;

    size_t                           length;

    buffer                           buffer_type;


};
