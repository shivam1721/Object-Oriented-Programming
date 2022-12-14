#include "puzzle.h"
#include "solver.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>

#include <algorithm>  // std::sort

int main(int argc, char* argv[]) {
    
    int nthreads;
    
    // Load the puzzles
    std::vector<Puzzle> puzzles;
    for(int i=1; i<argc; ++i) {
        try {
            std::string filename = std::string{argv[i]};
            std::ifstream ifs{filename};
            puzzles.push_back(Puzzle{filename, ifs});
        } catch(std::exception& e) {
            std::cerr << "Unable to open " << argv[i] << ": " 
                      << e.what() << std::endl;
        }
    }

    // Exit if one or more puzzles failed to load
    if((argc-1) != puzzles.size()) exit(-1);     
    
    // ----- All data loaded -----
    
    // Capture the solutions in a vector 
    std::vector<Solution> solutions;

    // Loop through all of the loaded puzzles
    for(Puzzle& puzzle : puzzles) {
    
        // thread pointer
        std::vector<std::thread*> threads;
    
        // Find each word in the current puzzle
        for(std::string word : puzzle) {
        
            // Instance a Solver, and use it to solve for the word
            Solver solver{puzzle};
            const puzzle_range = puzzles / nthreads;
            
            while(puzzles != 0){
                threads.push_back(new std::thread{
                    [this, puzzles]{
                        [this->solver(word);
                    }
                 
                });
            
            
            Solution s = solver.solve(word);
            solutions.push_back(s);
        }
    }
    //join thread
    for(auto t : threads) t->join();
    
    std::sort(solutions.begin(), solutions.end());
    for(Solution& s : solutions) std::cout << s << std::endl;
}
    
    
