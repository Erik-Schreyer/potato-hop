#ifndef POTATOSOLVER_HPP
#define POTATOSOLVER_HPP

#include <vector>
#include "potatoboard.hpp"

class PotatoSolver
{
public:
    PotatoSolver(PotatoBoard * board);
    ~PotatoSolver(){}

private:
    PotatoBoard* board_;
    std::vector<int> solution_;

public:
    bool solve();

    std::vector<int> getSolution(){
        return solution_;
    }

};

#endif // POTATOSOLVER_HPP
