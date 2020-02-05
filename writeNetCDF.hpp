//phys1610hw3

#ifndef writeNetCDF__hpp
#define writeNetCDF__hpp

#include <stdio.h>
#include <rarray>

/// @brief a function that appends myrarray to a file called filename
/// @param myrarray is an array to print
/// @param filename is the name of the file that we're prrinting to
void write_netcdf_file(int* myrarray, std::string filename, int dim1, int dim2);

#endif /* writeNetCDF_hpp */
