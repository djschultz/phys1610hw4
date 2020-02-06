//phys1610hw3

#ifndef readBinary__hpp
#define readBinary__hpp

#include <stdio.h>
#include <rarray>
/// @brief a function that appends myrarray to a file called filename
/// @param myrarray is an array to print
/// @param filename is the name of the file that we're prrinting to
void read_bin_file(std::string filename, int dim1, int dim2, int numReads);

#endif /* readBinary_hpp */
