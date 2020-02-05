// phys1610hw3

#include "append_array.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>

void write_bin_file(int* myrarray, std::string filename, int arraySize){
    std::ofstream f(filename, std::ofstream::binary | std::ofstream::app);
    f.write((char*)myrarray, arraySize);
    f.close();
}

