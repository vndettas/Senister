#include <gtest/gtest.h>
#include "../app/core/text/PieceOfTable.h"
#include "../app/core/text/Piece.h"

class PieceTestSmallBuffers : public testing::Test{
    protected:
  Piece piece_add{2, 5, buffer::add_buffer};
  Piece piece_read_only{2, 5, buffer::read_only_buffer};

};
TEST_F(PieceTestSmallBuffers, ShrinkFront){
  piece_add.shrink_Front();
  piece_read_only.shrink_Front();
  EXPECT_EQ(piece_add.offset, 3);
  EXPECT_EQ(piece_read_only.offset, 3);
  EXPECT_EQ(piece_add.length, 4);
  EXPECT_EQ(piece_read_only.length, 4);
}

TEST_F(PieceTestSmallBuffers, ShrinkFrontLength){
 piece_add.shrink_Front(4);
 piece_read_only.shrink_Front(4);
 EXPECT_EQ(piece_add.length, 1);
 EXPECT_EQ(piece_read_only.length, 1);
 EXPECT_EQ(piece_read_only.offset, 6);
 EXPECT_EQ(piece_add.offset, 6);
}

TEST_F(PieceTestSmallBuffers, ShrinkBackLengthLessZero){
 piece_add.shrink_Back(8);
 piece_read_only.shrink_Back(8);
 EXPECT_EQ(piece_add.length, 0);
 EXPECT_EQ(piece_read_only.length, 0);
}

TEST_F(PieceTestSmallBuffers, ShrinkBackLength){
 piece_add.shrink_Back(4);
 piece_read_only.shrink_Back(4);
 EXPECT_EQ(piece_add.length, 1);
 EXPECT_EQ(piece_read_only.length, 1);
}

TEST_F(PieceTestSmallBuffers, Idempotent){
 piece_add.shrink_Back(0);
 piece_read_only.shrink_Back(0);
 piece_add.shrink_Front(0);
 piece_read_only.shrink_Front(0);
 EXPECT_EQ(piece_add.length, 5);
 EXPECT_EQ(piece_read_only.length, 5);
 EXPECT_EQ(piece_add.offset, 2);
 EXPECT_EQ(piece_read_only.offset, 2);
}
 TEST_F(PieceTestSmallBuffers, FrontShrinkAllLength){
 piece_read_only.shrink_Front(5);
 piece_add.shrink_Front(5);
 EXPECT_EQ(piece_add.length, 0);
 EXPECT_EQ(piece_read_only.length, 0);
 }

 TEST_F(PieceTestSmallBuffers, BackShrinkAllLength){
 piece_add.shrink_Back(5);
 piece_read_only.shrink_Back(5);
 EXPECT_EQ(piece_add.length, 0);
 EXPECT_EQ(piece_read_only.length, 0);
 }

 class PieceTestZeroBuffers : public testing::Test{
     protected:

   Piece piece_add{0, 0, buffer::add_buffer};
   Piece piece_read_only{0, 0, buffer::read_only_buffer};
 };

 TEST_F(PieceTestZeroBuffers, ZeroPiece){
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

TEST(PieceTests, ShrinkBack){
  Piece piece_add{1, 5, buffer::add_buffer};
  Piece piece_read_only{1, 5, buffer::read_only_buffer};
  piece_add.shrink_Back();
  piece_read_only.shrink_Back();
  EXPECT_EQ(piece_add.length, 4);
  EXPECT_EQ(piece_read_only.length, 4);
}

TEST(PieceOfTableGetLengthMethod, TableInitialization){
  PieceOfTable table{QStringLiteral("abcvddfgjdfjgdfgdfgjfdgfjdklsgdsfgdsfgd")};
  EXPECT_EQ(table.get_Read_Buffer()->length(), QStringLiteral("abcvddfgjdfjgdfgdfgjfdgfjdklsgdsfgdsfgd").length());

}

class PieceOfTableGetCharMethod : public testing::Test{
    protected:
    PieceOfTableGetCharMethod() : table{QStringLiteral("abcvddfgjdfjgdfgdfgjfdgfjdklsgdsfgdsfgd")}
    {

    }

    PieceOfTable table;

};

TEST_F(PieceOfTableGetCharMethod, GetCharAt){
  EXPECT_EQ(table.get_Char_At(1), QChar{'b'});
  EXPECT_EQ(table.get_Char_At(6), QChar{'f'});
}

TEST_F(PieceOfTableGetCharMethod, GetCharAtZero){
  EXPECT_EQ(table.get_Char_At(0), QChar{'a'});
}

TEST_F(PieceOfTableGetCharMethod, GetCharAtMinus){
  EXPECT_EQ(table.get_Char_At(-5), QChar{});
}

TEST_F(PieceOfTableGetCharMethod, GetCharAtBiggerThanTextItself){
  EXPECT_EQ(table.get_Char_At(45), QChar{});
  EXPECT_EQ(table.get_Char_At(1239123891283129381923819), QChar{});
}

class PieceOfTableEraseMethod : public testing::Test{
    protected:
    PieceOfTableEraseMethod() : table{QStringLiteral("I lost all my friends today")}
    {

    }

    PieceOfTable table;

    QString text{"I lost all my friends today"};
};

TEST_F(PieceOfTableEraseMethod, ZeroCharacter){
  table.erase(0);
  EXPECT_EQ(table.get_Piece_Vector()[0].offset, 1);
}

TEST_F(PieceOfTableEraseMethod, ZeroCharacterTwice){
  table.erase(0);
  table.erase(0);
  EXPECT_EQ(table.get_Piece_Vector()[0].offset, 2);
}

TEST_F(PieceOfTableEraseMethod, LastCharInPiece){
  uint32_t piece_length = table.get_Piece_Vector()[0].length;
  table.print_Logs();
  table.erase(text.length()-1);
  --piece_length;
  EXPECT_EQ(table.get_Piece_Vector()[0].length, piece_length);
  --piece_length;
  table.print_Logs();
  EXPECT_EQ(table.get_Piece_Vector()[0].length, piece_length);
}
