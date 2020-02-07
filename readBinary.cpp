// phys1610hw3

#include "readBinary.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>
#include "ants.hpp"
#include "report.hpp"

void read_bin_file(std::string filename, int length, int numReads, int initAnts, int outputInc){
    rarray<int,2> number_of_ants_on_table(length, length); // define a char rarray into which we will read the binary file
    rarray<char,2> my_charrarray(length, length); // define an int rarray to store the chars in integer form
    int charDim = length*length*sizeof(char); // the amount of char space one data set occupies in the binary file
    std::ifstream f(filename, std::ifstream::in | std::ifstream::binary); // open up a stream to the binary file of name filename
    int total_ants = initAnts; // set initAnts to total_ants
    rarray<int,1> antData(3); // define and array to keep min ants, max ants, and total ants in
    antData[0] = total_ants; // set min ants to be total_ants
    antData[1] = 0; // set max ants to be zero
    antData[2] = 0; // set total ants to be zero
    for(int k = 0; k < numReads; k++){ 
        f.read(my_charrarray.data(), charDim); // read the binary file into the char rarray
        for(int i = 0; i < length; i++){
            for(int j = 0; j < length; j++){
                number_of_ants_on_table[i][j] = my_charrarray[i][j]; // change the char rarray into an int rarray
            }
        }
        countAnts(length, antData, number_of_ants_on_table); // count the ants but use the int rarray
        report(k*outputInc, antData); // report the results to the console
        antData[0] = total_ants; // reset the antData
        antData[1] = 0;
        antData[2] = 0;
    }
}

