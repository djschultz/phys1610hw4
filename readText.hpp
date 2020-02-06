//phys1610hw3

#ifndef readText__hpp
#define readText__hpp

#include <stdio.h>
#include <rarray>
/// @brief a function that appends myrarray to a file called filename
/// @param myrarray is an array to print
/// @param filename is the name of the file that we're prrinting to
void read_text_file(rarray<int,2> myrarray, std::string filename, int ignore);

#endif /* readText_hpp */
