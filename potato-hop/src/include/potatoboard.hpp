#ifndef POTATOBOARD_HPP
#define POTATOBOARD_HPP

#include <vector>

/*      The board square numbering:
 *
 *
 *  X  X  X  X  X  X  X  X  X
 *  X  X  X  O  O  O  X  X  X
 *  X  X  O  O  O  O  O  X  X
 *  X  O  O  O  O  O  O  O  X
 *  X  O  O  O  O  O  O  O  X
 *  X  O  O  O  O  O  O  O  X
 *  X  X  O  O  O  O  O  X  X
 *  X  X  X  O  O  O  X  X  X
 *  X  X  X  X  X  X  X  X  X
 *
 *
 *  X  X  X  X  X  X  X  X  X
 *  X  X  X  72 73 74 X  X  X
 *  X  X  61 62 63 64 65 X  X
 *  X  50 51 52 53 54 55 56 X
 *  X  40 41 42 43 44 45 46 X
 *  X  30 31 32 33 34 35 36 X
 *  X  X  21 22 23 24 25  X  X
 *  X  X  X  12 13 14 X  X  X
 *  X  X  X  X  X  X  X  X  X
 *
 * */

class PotatoBoard
{
public:
    PotatoBoard(std::vector<int> potatoes, std::vector<std::vector<int>> possMoves);
    ~PotatoBoard(){
        delete[] currentBoard_;
    }

private:
    int* currentBoard_;
    std::vector<std::vector<int>> possMoves_;

public:
    bool makeMove(int from, int to);

    std::vector<int> getPotatoes();

};

#endif // POTATOBOARD_HPP
