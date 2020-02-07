// phys1610hw3

#include "readText.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>
#include "ants.hpp"
#include "report.hpp"

void read_text_file(int length, std::string filename, int numReads, int initAnts, int outputInc){
    std::ifstream fin(filename, std::fstream::in); // open a reading stream for a text file
    rarray<int,2> number_of_ants_on_table(length,length); // make an rarray in which to store the number of ants on the table
    rarray<int,1> antData(3); // define the ants data to keep track of min, max, and total ants
    int total_ants = initAnts; // set total_ants to initAnts
    antData[0] = total_ants; 
    antData[1] = 0;
    antData[2] = 0;
    for(int i = 0; i < numReads ; i++){
        fin >> number_of_ants_on_table; // put the d ata from the file into the rarray
        countAnts(length, antData, number_of_ants_on_table); // count the number of ants on the table
        report(i*outputInc, antData); // print the result of counting ants to the console
        antData[0] = total_ants;
        antData[1] = 0;
        antData[2] = 0;      
    }
    fin.close();
}

