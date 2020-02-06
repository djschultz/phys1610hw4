//phys1610hw3

#ifndef readNetCDF__hpp
#define readNetCDF__hpp

#include <stdio.h>
#include <rarray>

/// @brief a function that appends myrarray to a file called filename
/// @param myrarray is an array to print
/// @param filename is the name of the file that we're prrinting to
void read_netcdf_file(std::string filename, int numSteps, int length);

#endif /* readNetCDF_hpp */
