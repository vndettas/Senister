#include <gtest/gtest.h>
#include "../app/core/text/PieceOfTable.h"
#include "../app/core/text/Piece.h"

class PieceTest : public testing::Test{
    protected:
  Piece piece_add{2, 5, buffer::add_buffer};
  Piece piece_read_only{2, 5, buffer::read_only_buffer};

};

TEST(PieceTests, ShrinkBack){
  Piece piece_add{1, 5, buffer::add_buffer};
  Piece piece_read_only{1, 5, buffer::read_only_buffer};
  piece_add.shrink_Back();
  piece_read_only.shrink_Back();
  EXPECT_EQ(piece_add.length, 4);
  EXPECT_EQ(piece_read_only.length, 4);
}

TEST_F(PieceTest, ShrinkFront){
  piece_add.shrink_Front();
  piece_read_only.shrink_Front();
  EXPECT_EQ(piece_add.offset, 3);
  EXPECT_EQ(piece_read_only.offset, 3);
  EXPECT_EQ(piece_add.length, 4);
  EXPECT_EQ(piece_read_only.length, 4);
}

TEST_F(PieceTest, ShrinkFrontLength){
 piece_add.shrink_Front(4);
 piece_read_only.shrink_Front(4);
 EXPECT_EQ(piece_add.length, 1);
 EXPECT_EQ(piece_read_only.length, 1);
 EXPECT_EQ(piece_read_only.offset, 6);
 EXPECT_EQ(piece_add.offset, 6);
}

TEST_F(PieceTest, ShrinkBackLengthLessZero){
 piece_add.shrink_Back(8);
 piece_read_only.shrink_Back(8);
 EXPECT_EQ(piece_add.length, 0);
 EXPECT_EQ(piece_read_only.length, 0);
}

TEST_F(PieceTest, ShrinkBackLength){
 piece_add.shrink_Back(4);
 piece_read_only.shrink_Back(4);
 EXPECT_EQ(piece_add.length, 1);
 EXPECT_EQ(piece_read_only.length, 1);
}

TEST_F(PieceTest, Idempotent){
 piece_add.shrink_Back(0);
 piece_read_only.shrink_Back(0);
 piece_add.shrink_Front(0);
 piece_read_only.shrink_Front(0);
 EXPECT_EQ(piece_add.length, 5);
 EXPECT_EQ(piece_read_only.length, 5);
 EXPECT_EQ(piece_add.offset, 2);
 EXPECT_EQ(piece_read_only.offset, 2);
}
 TEST_F(PieceTest, FrontShrinkAllLength){
 piece_read_only.shrink_Front(5);
 piece_add.shrink_Front(5);
 EXPECT_EQ(piece_add.length, 0);
 EXPECT_EQ(piece_read_only.length, 0);
 }

 TEST_F(PieceTest, BackShrinkAllLength){
 piece_add.shrink_Back(5);
 piece_read_only.shrink_Back(5);
 EXPECT_EQ(piece_add.length, 0);
 EXPECT_EQ(piece_read_only.length, 0);
 }

 TEST(PieceTests, ZeroPiece){
 Piece piece_add{0, 0, buffer::add_buffer};
 Piece piece_read_only{0, 0, buffer::read_only_buffer};
 piece_read_only.shrink_Back();
 piece_read_only.shrink_Back(5);
 piece_add.shrink_Back();
 piece_add.shrink_Back(5);
 piece_read_only.shrink_Front();
 piece_read_only.shrink_Front(5);
 piece_add.shrink_Front();
 piece_add.shrink_Front(5);
 EXPECT_EQ(piece_add.length, 0);
 EXPECT_EQ(piece_read_only.length, 0);
 }
