// phys1610hw3

#include "writeBinary.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>

void write_bin_file(rarray<int,2> myrarray, std::string filename, int dim1, int dim2){
    rarray<char,2> my_charrarray(dim1, dim2);
    for(int i = 0; i < dim1; i++){
        for(int j = 0; j < dim2; j++){
            my_charrarray[i][j] = myrarray[i][j];
        }
    }
    std::ofstream f(filename, std::ofstream::binary | std::ofstream::app);
    f.write(my_charrarray.data(), dim1*dim2);
    f.close();
}

