// phys1610hw3

#include "writeText.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>

void write_text_file(rarray<int,2> number_of_ants_on_table, std::string filename){
    std::ofstream fout; // define an out stream 
    fout.open(filename, std::ios::app); // open a file in append mode
    fout << number_of_ants_on_table << std::endl; // write the number_of_ants_on_table to the file
    fout.close(); // close the fiel
}

