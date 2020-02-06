//phys1610hw3

#ifndef writeNetCDF__hpp
#define writeNetCDF__hpp

#include <stdio.h>
#include <rarray>
#include <netcdf>

/// @brief a function that appends myrarray to a file called filename
/// @param myrarray is an array to print
/// @param filename is the name of the file that we're prrinting to
netCDF::NcVar create_netcdf_file(std::string filename, int dim1, int dim2, netCDF::NcFile& dataFile);

void write_netcdf_file(rarray<int,2> myrarray, netCDF::NcVar antsVar, int dim1, int dim2, int numDataStep, netCDF::NcFile& file );

#endif /* writeNetCDF_hpp */
