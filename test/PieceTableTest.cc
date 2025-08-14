#include <gtest/gtest.h>
#include "../core/Text/PieceOfTable.h"

TEST(PieceTest, ShrinkBack){
  Piece piece_add{0, 5, buffer::add_buffer};
  Piece piece_read_only{0, 5, buffer::read_only_buffer};
  EXPECT_EQ(piece_add.length, 5);
  EXPECT_EQ(piece_read_only.length, 5);
  piece_add.shrink_Back();
  piece_read_only.shrink_Back();
  EXPECT_EQ(piece_add.length, 4);
  EXPECT_EQ(piece_read_only.length, 4);
}

TEST(PieceTest, ShrinkFront){
  Piece piece_add{1, 5, buffer::add_buffer};
  Piece piece_read_only{1, 5, buffer::read_only_buffer};
  piece_add.shrink_Front();
  piece_read_only.shrink_Front();
  EXPECT_EQ(piece_add.offset, 2);
  EXPECT_EQ(piece_read_only.offset, 2);
}

TEST(PieceTest, ShrinkBackZero){
  Piece piece_add{1, 1, buffer::add_buffer};
  Piece piece_red_only{1, 1, buffer::read_only_buffer};
  //to do they should be deleted from vector
}