//phys1610hw3

#ifndef readNetCDF__hpp
#define readNetCDF__hpp

#include <stdio.h>
#include <rarray>

/// @brief a function that appends myrarray to a file called filename
/// @param myrarray is an array to print
/// @param filename is the name of the file that we're prrinting to
void read_netcdf_file(int* myrarray, std::string filename);

#endif /* readNetCDF_hpp */
