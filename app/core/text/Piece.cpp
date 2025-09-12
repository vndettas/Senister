//
// SPDX-License-Identifier: MIT
// /file  : Piece.cpp
// Last modified: 2025-09-11 21:17
//

#include "Piece.h"

Piece::Piece(size_t offset, size_t length, buffer bufferType) : offset(offset), length(length), buffer_type(bufferType) {}

void
Piece::shrink_Front()
{

  this->offset++ && this->length--;
}

void
Piece::shrink_Back()
{

  this->length--;

}

void
Piece::shrink_Back(size_t _length)
{

  if(_length < this->length){
    this->length -= _length;
  }

}

void
Piece::set_Length(size_t _length)
{

  this->length = _length;

}

void
Piece::shrink_Front(size_t length)
{

  this->offset += length;

}
