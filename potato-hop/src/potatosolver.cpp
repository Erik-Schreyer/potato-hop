#include "potatoboard.hpp"
#include "potatosolver.hpp"

#include <algorithm>
#include <iostream>

PotatoSolver::PotatoSolver(PotatoBoard* board) :
    board_(board)
{
}

bool PotatoSolver::solve(){
    std::vector<int> moveList = board_->getMoveList();
    for(auto move : moveList){
        bool suc = board_->makeMove(move);

//        board_->printCurrentBoard();

        if(!suc){return false;}
        solution_.push_back(move);
        for(auto solStep : solution_){
            std::cout<< solStep;
        }
        std::cout << '\n';
        if(board_->getNumPotatoes()==1){
            return true;
        }
        bool solved = this->solve();

        if(solved){return true;}
        bool undo = board_->undoMove(move);
        if(!undo){return false;}
        solution_.pop_back();
    }
    return false;
}
