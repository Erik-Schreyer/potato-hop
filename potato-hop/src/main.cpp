#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "potatoboard.hpp"
#include "potatosolver.hpp"


//     /home/erik/potato-hop/potato-hop/pettersonSetUp.txt

PotatoBoard * setUpBoard(std::string configureFilePath){
    std::ifstream configFile(configureFilePath);

    std::stringstream buffer;
    std::string currentLine;

    std::getline(configFile,currentLine);
    buffer << currentLine;
    int size;
    buffer >> size;

    buffer.clear();
    std::getline(configFile,currentLine);
    buffer << currentLine;

    std::string potatoes;
    std::string emptySquares;
    std::getline(buffer,potatoes,'#');
    std::getline(buffer, emptySquares);
    std::stringstream potatoes_stream(potatoes);
    std::stringstream emptySquare_stream(emptySquares);

    std::vector<int> potatoesVec;
    int potato;
    while(potatoes_stream >> potato){
//        std::cout<<potato<<'\n';
        potatoesVec.push_back(potato);
    }

    std::vector<int> emptySquareVec;
    int emptySquare;
    while(emptySquare_stream >> emptySquare){
//        std::cout<<emptySquare<<'\n';
        emptySquareVec.push_back(emptySquare);
    }

    std::vector<int> movesVec;
    int move;
    buffer.clear();
    while(std::getline(configFile,currentLine)){
        buffer << currentLine;
        while(buffer >> move){
//            std::cout<<move<<'\n';
            movesVec.push_back(move);
        }
        buffer.clear();
    }

    PotatoBoard * board =new PotatoBoard(potatoesVec,emptySquareVec,movesVec,size);
/*    for(int i = 0; i< 75 ;i++){
        std::cout << board->getCurrentBoard()[i];
        if(i%10==9){std::cout <<'\n';}
    }
*/
    return board;

}


int main()
{
    std::cout << "Configuration file path:" << std::endl;
    std::string configureFilePath;
    std::cin >> configureFilePath;

    PotatoBoard * board = setUpBoard(configureFilePath);
    board->printCurrentBoard();
    PotatoSolver * solver = new PotatoSolver(board);

    bool solved = solver->solve();
    if(solved){
        std::cout<< "It it is solvable! :)\n";
        std::cout<< "Save solution to file:\n";

        std::string solutionFilePath;

        std::cin >> solutionFilePath;
        std::ofstream outF(solutionFilePath);
        for(auto move : solver->getSolution()){
            outF << move << '\n';
        }
    }
    if(!solved){
        std::cout << "It has no solution :(\n";
    }

    return 0;
}
