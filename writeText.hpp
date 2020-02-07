//phys1610hw3

#ifndef writeText__hpp
#define writeText__hpp

#include <stdio.h>
#include <rarray>
/// @brief a function that appends myrarray to a file called filename
/// @param number_of_ants_on_table array containing the number of ants at each point on the table
/// @param filename is the name of the file that we're prrinting to
void write_text_file(rarray<int,2> number_of_ants_on_table, std::string filename);

#endif /* writeText_hpp */
