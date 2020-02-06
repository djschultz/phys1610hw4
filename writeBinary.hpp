//phys1610hw3

#ifndef writeBinary__hpp
#define writeBinary__hpp

#include <stdio.h>
#include <rarray>
/// @brief a function that appends myrarray to a file called filename
/// @param myrarray is an array to print
/// @param filename is the name of the file that we're prrinting to
void write_bin_file(rarray<int,2> myrarray, std::string filename, int dim1, int dim2);

#endif /* writeBinary_hpp */
