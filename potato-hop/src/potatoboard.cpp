#include "potatoboard.hpp"
#include <algorithm>
#include <iostream>

PotatoBoard::PotatoBoard(std::vector<int> potatoes,std::vector<int> emptySquares, std::vector<int> possMoves, int size) :
    possMoves_(possMoves),
    size_(size)
{

    std::vector<int> currentBoard(size,2);
    for(auto potato : potatoes){
        currentBoard[potato] =1;
    }
    numPotatoes_=potatoes.size();
    for(auto empty : emptySquares){
        currentBoard[empty]=0;
    }
    currentBoard_=currentBoard;
}


std::vector<int> PotatoBoard::getPotatoes(){
    std::vector<int> potatoes;
    unsigned int i;
    for(i=0; i<= 36 ; i++){
        if(currentBoard_[i]!=0){
            potatoes.push_back(i);
        }
    }
    return potatoes;
}


bool PotatoBoard::makeMove(int move){
    bool possMove = std::find(possMoves_.begin(),possMoves_.end(),move)!=possMoves_.end();
    int from = move/10000;
    int inBetweeen = (move%10000)/100;
    int to = move%100;
    bool isLegal = possMove && currentBoard_[from]==1 && currentBoard_[inBetweeen]==1 && currentBoard_[to]==0;
    if(isLegal){
        currentBoard_[from]=0;
        currentBoard_[inBetweeen]=0;
        currentBoard_[to]=1;
        numPotatoes_--;
    }
    return isLegal;

}

bool PotatoBoard::undoMove(int move){
    bool possMove = std::find(possMoves_.begin(),possMoves_.end(),move)!=possMoves_.end();
    int to = move/10000;
    int inBetweeen = (move%10000)/100;
    int from = move%100;
    bool isLegal = possMove && currentBoard_[from]==1 && currentBoard_[inBetweeen]==0 && currentBoard_[to]==0;
    if(isLegal){
        currentBoard_[from]=0;
        currentBoard_[inBetweeen]=1;
        currentBoard_[to]=1;
        numPotatoes_++;
    }
    return isLegal;

}

std::vector<int> PotatoBoard::getMoveList(){
    std::vector<int> moveList;

    for(auto move : possMoves_){
        int from = move/10000;
        int inBetweeen = (move%10000)/100;
        int to = move%100;

        bool isLegal = currentBoard_[from]==1 && currentBoard_[inBetweeen]==1 && currentBoard_[to]==0;
//        std::cout << "current board: " << currentBoard_[from] << currentBoard_[inBetweeen] << currentBoard_[to] << '\n';
//        std::cout << "move "<< move << "is: " << isLegal << '\n';
        if(isLegal){
            moveList.push_back(move);
            std::cout << move << '\n';
        }
    }
    return moveList;
}

void PotatoBoard::printCurrentBoard(){
    for(unsigned int i = 0; i< currentBoard_.size() ;i++){
        std::cout << currentBoard_[i];
        if(i%10==9){std::cout <<'\n';}
    }
    std::cout << "\n\n";
}
