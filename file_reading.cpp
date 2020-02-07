#include <iostream>
#include <rarray>
#include <fstream>
#include "ants.hpp"
#include "report.hpp"
#include "readText.hpp"
#include "readBinary.hpp"
#include "readNetCDF.hpp"

// Function to read different kinds of files and print the output to the console
//The function takes 6 input arguments, as opposed to antsontable.cpp, which takes 7. there is no seed given here, but all other arguments are the same
int main(int argc, const char * argv[])
{
    // ====================== put command line parameters into variables  ==================== //
    std::string writeOption = argv[1]; // -r, -b, -n depending on if you want to write a text, binary, or netcdf file
    std::string filename = argv[2]; // the name of the file you're writing to
    int outputInc = atoi(argv[3]); // the number of timesteps between consecutive writings to the file
    int length = atoi(argv[4]); // the length of the table
    int total_ants = atoi(argv[5]); // the total number of ants at the beginning of the simulation
    int ntimesteps = atoi(argv[6]); // the total number of time steps in the simulation


    // ===================== start simulation ================= //
    int numReads = ntimesteps/outputInc; // the number of times we will read the file

    if(writeOption.compare("-r")==0){
        read_text_file(length, filename, numReads, total_ants, outputInc); // read the text file and print the ants summary to the console
    }
    if(writeOption.compare("-b")==0){
        read_bin_file(filename, length, numReads, total_ants, outputInc); // read the binary file and print the ants summary to the console
    }
    if(writeOption.compare("-n")==0){
        read_netcdf_file(filename, numReads, length, total_ants, outputInc); // read the netcdf file and print the ants summary to the console
    }

    return 0;
}




