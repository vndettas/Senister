#include <gtest/gtest.h>
#include "../app/core/text/PieceOfTable.h"

TEST(PieceTest, ShrinkBack){
  Piece piece_add{1, 5, buffer::add_buffer};
  Piece piece_read_only{1, 5, buffer::read_only_buffer};
  piece_add.shrink_Back();
  piece_read_only.shrink_Back();
  EXPECT_EQ(piece_add.length, 4);
  EXPECT_EQ(piece_read_only.length, 4);
}

TEST(PieceTest, ShrinkFront){
  Piece piece_add{2, 5, buffer::add_buffer};
  Piece piece_read_only{2, 5, buffer::read_only_buffer};
  piece_add.shrink_Front();
  piece_read_only.shrink_Front();
  EXPECT_EQ(piece_add.offset, 3);
  EXPECT_EQ(piece_read_only.offset, 3);
  EXPECT_EQ(piece_add.length, 4);
  EXPECT_EQ(piece_read_only.length, 4);
}

TEST(PieceTest, ShrinkFrontLength){
 Piece piece_add{2, 5, buffer::add_buffer};
 Piece piece_read_only{2, 5, buffer::read_only_buffer};
 piece_add.shrink_Front(4);
 piece_read_only.shrink_Front(4);
 EXPECT_EQ(piece_add.length, 0);
 EXPECT_EQ(piece_read_only.length, 0);
}

TEST(PieceTest, ShrinkBackLengthLessZero){
 Piece piece_add{2, 5, buffer::add_buffer};
 Piece piece_read_only{2, 5, buffer::read_only_buffer};
 piece_add.shrink_Back(8);
 piece_read_only.shrink_Back(8);
 EXPECT_EQ(piece_add.length, 0);
 EXPECT_EQ(piece_read_only.length, 0);
}

TEST(PieceTest, ShrinkBackLength){
 Piece piece_add{2, 5, buffer::add_buffer};
 Piece piece_read_only{2, 5, buffer::read_only_buffer};
 piece_add.shrink_Back(4);
 piece_read_only.shrink_Back(4);
 EXPECT_EQ(piece_add.length, 1);
 EXPECT_EQ(piece_read_only.length, 1);
}

TEST(PieceTest, Idempotent){
 Piece piece_add{2, 5, buffer::add_buffer};
 Piece piece_read_only{2, 5, buffer::read_only_buffer};
 piece_add.shrink_Back(0);
 piece_read_only.shrink_Back(0);
 piece_add.shrink_Front();
 piece_read_only.shrink_Front();
 EXPECT_EQ(piece_add.length, 5);
 EXPECT_EQ(piece_read_only.length, 5);
 EXPECT_EQ(piece_add.offset, 2);
 EXPECT_EQ(piece_read_only.offset, 2);
}
