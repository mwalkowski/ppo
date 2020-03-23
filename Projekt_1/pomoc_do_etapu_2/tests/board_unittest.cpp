#include <gtest/gtest.h>
#include "../src/board.h"

// predefined mine field layout:
// field at coordinates x,y has mine, if any of the following is true
// - x==y (all fields on main diagonal have mines)
// - y==0 (all fields in first row have mines)
// - x==0 and y%2 == 0 (every second field in first column has mine)
//
// Assuming we have 9x7 board size, debug_display() should show:

// [M..][M..][M..][M..][M..][M..][M..][M..][M..]
// [...][M..][...][...][...][...][...][...][...]
// [M..][...][M..][...][...][...][...][...][...]
// [...][...][...][M..][...][...][...][...][...]
// [M..][...][...][...][M..][...][...][...][...]
// [...][...][...][...][...][M..][...][...][...]
// [M..][...][...][...][...][...][M..][...][...]

namespace {

const unsigned int WIDTH = 9;
const unsigned int HEIGHT = 7;

// - DEBUG  - predefined mine layout
TEST(MinesweeperBoardTest, getMineCountDebug) {
    MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
    EXPECT_EQ(18,  uut.getMineCount());
}

// - EASY   - 10% of game fields with mines (random)
TEST(MinesweeperBoardTest, getMineCountEasy) {
    MinesweeperBoard uut(WIDTH, HEIGHT, EASY);
    EXPECT_EQ(6,  uut.getMineCount());
}

// - NORMAL - 20% of game fields with mines (random)
TEST(MinesweeperBoardTest, getMineCountNormal) {
    MinesweeperBoard uut(WIDTH, HEIGHT, NORMAL);
    EXPECT_EQ(12,  uut.getMineCount());
}

// - HARD   - 30% of game fields with mines (random)
TEST(MinesweeperBoardTest, getMineCountHard) {
    MinesweeperBoard uut(WIDTH, HEIGHT, HARD);
    EXPECT_EQ(18,  uut.getMineCount());
}

// simple getters
TEST(MinesweeperBoardTest, getBoardWidth) {
    MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
    EXPECT_EQ(WIDTH,  uut.getBoardWidth());
}

// simple getters
TEST(MinesweeperBoardTest, getBoardHeight) {
    MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
    EXPECT_EQ(HEIGHT,  uut.getBoardHeight());
}

// count mines around (x,y) position
// if the field at (x,y) was not revealed - return -1
TEST(MinesweeperBoardTest, countMinesArroundXYIftheFieldWasNotRevealed) {
    MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
    EXPECT_FALSE(uut.isRevealed(1, 0));
    EXPECT_EQ(-1, uut.countMines(1, 0));
}

// count mines around (x,y) position
// if the field at (x,y) was not revealed - return -1
TEST(MinesweeperBoardTest, countMinesIfEitherXOrYIsOutsideBoard) {
    MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
    EXPECT_EQ(-1, uut.countMines(-1, 0));
    EXPECT_EQ(-1, uut.countMines(0, -1));
    EXPECT_EQ(-1, uut.countMines(-1, -1));

    EXPECT_EQ(-1, uut.countMines(WIDTH + 1, 0));
    EXPECT_EQ(-1, uut.countMines(0, HEIGHT + 1));
    EXPECT_EQ(-1, uut.countMines(WIDTH + 1, HEIGHT + 1));
}

// count mines around (x,y) position
// Examples for DEBUG layout (assuming the field is already revealed)
// - countMines(0,1) should return 4
// - countMines(9,2) should return 0
// - countMines(1,2) should return 3
// - countMines(7,6) should return 1
TEST(MinesweeperBoardTest, countMinesIfFieldIsRelealed) {
    MinesweeperBoard uut(WIDTH, HEIGHT, DEBUG);
    
    uut.revealField(0, 1);
    EXPECT_EQ(4, uut.countMines(0, 1));

    uut.revealField(9, 2);
    EXPECT_EQ(0, uut.countMines(9, 2));

    uut.revealField(1, 2);
    EXPECT_EQ(3, uut.countMines(1, 2));

    uut.revealField(7, 6);
    EXPECT_EQ(1, uut.countMines(7, 6));
}

}
