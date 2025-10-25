#include "Piece.h"

Piece::Piece(size_t offset, size_t length, buffer bufferType) : offset(offset), length(length), buffer_type(bufferType) {}

void
Piece::shrink_Front()
{

  if(this->length > 1){
  this->offset++;
  this->shrink_Back();
  }

}

void
Piece::shrink_Back()
{

  if(this->length > 0){
  this->length--;
  }

}

void
Piece::shrink_Back(size_t _length)
{

  if(_length > this->length){
    this->length = 0;
  } else {
      this->length -= _length;
  }

}

void
Piece::set_Length(size_t _length)
{

  this->length = _length;

}

void
Piece::shrink_Front(size_t _length)
{
    if(_length > this->length){
        this->length = 0;
    } else{
        this->offset += _length;
        this->shrink_Back(_length);
    }

}
