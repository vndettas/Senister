//
// SPDX-License-Identifier: MIT
// /file  : Piece.h
// Last modified: 2025-09-11 21:17
//

class Piece {
public:

    Piece                                            (size_t offset, size_t length, buffer bufferType);

    void                                             shrink_Front();

    void                                             shrink_Front(size_t length);

    void                                             shrink_Back();

    void                                             shrink_Back(size_t length);

    void                                             set_Length(size_t length);

 private:

    size_t                           offset;

    size_t                           length;

    buffer                           buffer_type;


};
