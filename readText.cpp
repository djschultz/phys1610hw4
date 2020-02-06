// phys1610hw3

#include "readText.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>

void read_text_file(rarray<int,2> myrarray, std::string filename, int ignore){
    std::ifstream fin;
    fin.open(filename, std::ios::app);
    for(int i = 0; i < ignore; i++){
        fin.ignore('\n');
    }
    fin >> myrarray;
    fin.close();
    std::cout << myrarray;
}

