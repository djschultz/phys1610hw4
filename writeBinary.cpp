// phys1610hw3

#include "writeBinary.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>

void write_bin_file(rarray<int,2> number_of_ants_on_table, std::string filename, int length){
    rarray<char,2> my_charrarray(length, length); //define an rarray of chars to put into the binary file
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            my_charrarray[i][j] = number_of_ants_on_table[i][j]; // convert the input integer rarray into a char rarray
        }
    }
    std::ofstream f(filename, std::ofstream::binary | std::ofstream::app); // open a stream to a binary file
    f.write(my_charrarray.data(), length*length); // put the char rarray into the file
    f.close(); //close the stream
}

