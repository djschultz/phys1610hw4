// phys1610hw3

#include "writeText.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>

void write_text_file(rarray<int,2> myrarray, std::string filename){
    std::ofstream fout;
    fout.open(filename, std::ios::app);
    fout << myrarray << std::endl;
    fout.close();
}

