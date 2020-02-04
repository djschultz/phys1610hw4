// phys1610hw3

#include "append_array.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>

void print_rarray(rarray<int,2> myrarray, std::string filename){
    std::ofstream f(filename, std::ios::binary);
    f.write("o");
    f.close();
}

