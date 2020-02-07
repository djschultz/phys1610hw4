//phys1610hw3

#ifndef readBinary__hpp
#define readBinary__hpp

#include <stdio.h>
#include <rarray>

/// @brief function to read a binary file and print the contents to the console
/// @param filename the name of the file to be read
/// @param length the side length of the square datasets contained within the file
/// @param numReads the number of datasets within the file
/// @param initAnts the initial number of ants in the simulation
/// @param outputInc the number of time steps in between consecutive outputs
void read_bin_file(std::string filename, int length, int numReads, int initAnts, int outputInc);

#endif /* readBinary_hpp */
