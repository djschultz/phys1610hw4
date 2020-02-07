//phys1610hw3

#ifndef writeBinary__hpp
#define writeBinary__hpp

#include <stdio.h>
#include <rarray>

/// @brief a function that appends myrarray to a file called filename
/// @param number_of_ants_on_table is an array saying how many ants are on each point on the table
/// @param filename is the name of the file that we're prrinting to
/// @param length the side length of square data sets in the binary file
void write_bin_file(rarray<int,2> number_of_ants_on_table, std::string filename, int length);

#endif /* writeBinary_hpp */
