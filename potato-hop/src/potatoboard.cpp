#include "potatoeboard.hpp"
#include <algorithm>

PotatoBoard::PotatoBoard(std::vector<int> potatoes,std::vector<int> emptySquares, std::vector<std::vector<int>> possMoves) :
    possMoves_(possMoves)
{
    int currentBoard[73];
    std::fill_n(currentBoard,73,-1);
    for(auto potato : potatoes){
        currentBoard[potato] =1;
    }
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

bool PotatoBoard::makeMove(int from, int to){
    bool legalMove = std::find(possMoves_[from].begin(),possMoves_[from].end(),to)!=possMoves_[from].end();
  //  if(legalMove && currentBoard_[from]&&currentBo){

    }
}
