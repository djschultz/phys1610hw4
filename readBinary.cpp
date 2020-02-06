// phys1610hw3

#include "readBinary.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>

void read_bin_file(std::string filename, int dim1, int dim2){
    rarray<int,2> myrarray(dim1, dim2);
    rarray<char,2> my_charrarray(dim1, dim2);
    int charDim = dim1*dim2*sizeof(char);
    std::ifstream f(filename, std::ifstream::in | std::ifstream::binary);
    f.read(my_charrarray.data(), charDim);
    for(int i = 0; i < dim1; i++){
        for(int j = 0; j < dim2; j++){
             myrarray[i][j] =  my_charrarray[i][j];
        }
    }
    std::cout<< myrarray;;
}

