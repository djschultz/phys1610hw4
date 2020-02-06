// phys1610hw3

#include "readText.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>
#include "ants.hpp"
#include "report.hpp"

void read_text_file(int length, std::string filename, int numReads){
    std::ifstream fin(filename, std::fstream::in);
    rarray<int,2> myrarray(length,length);
    rarray<int,1> antData(3);
    int total_ants = 40000;
    antData[0] = total_ants;
    antData[1] = 0;
    antData[2] = 0;
    for(int i = 0; i < numReads ; i++){
        fin >> myrarray;
        countAnts(length, antData, myrarray);
        report(i*1000+1, antData);
        antData[0] = total_ants;
        antData[1] = 0;
        antData[2] = 0;      
    }
    fin.close();
}

