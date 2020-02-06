// phys1610hw3

#include "readBinary.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>
#include "ants.hpp"
#include "report.hpp"

void read_bin_file(std::string filename, int dim1, int dim2, int numReads){
    rarray<int,2> number_of_ants_on_table(dim1, dim2);
    rarray<char,2> my_charrarray(dim1, dim2);
    int charDim = dim1*dim2*sizeof(char);
    std::ifstream f(filename, std::ifstream::in | std::ifstream::binary);
    int total_ants = 40000;
    rarray<int,1> antData(3);
    antData[0] = total_ants;
    antData[1] = 0;
    antData[2] = 0;
    for(int k = 0; k < numReads; k++){
        f.read(my_charrarray.data(), charDim);
        for(int i = 0; i < dim1; i++){
            for(int j = 0; j < dim2; j++){
                number_of_ants_on_table[i][j] = my_charrarray[i][j];
            }
        }
        countAnts(dim1, antData, number_of_ants_on_table);
        report(1+k*1000, antData);
        antData[0] = total_ants;
        antData[1] = 0;
        antData[2] = 0;
    }
}

