#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "MinesweeperBoard.h"

int main() {
    srand (time(nullptr));
    MinesweeperBoard Board;
    Board.debug_display();
    Board.setField_Rand();
    Board.debug_display();
    return 0;
}
