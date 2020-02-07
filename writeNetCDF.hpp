//phys1610hw3

#ifndef writeNetCDF__hpp
#define writeNetCDF__hpp

#include <stdio.h>
#include <rarray>
#include <netcdf>

/// @brief a function to define a netCDf file
/// @param filename the name that the NetCDF file will be
/// @param length the side length of the 2D data we are putting into the netCdf file
/// @param the name of the variable that we are putting into the file
void define_netcdf_file(std::string filename, int length, std::string dataName);

/// @brief a function to write to a given NetCDf file whose name is filename; we are writing in the variable dataName
/// @param number_of_ants_on_table is the number of ants at each point on the table
/// @param filename the name of the file which we are writing to
/// @param length the side length of the 2D data we are putting into the netCDF file
/// @param numDataStep the layer into which we put this 2D data
/// @param dataName the name of the variable that we are putting into the file
void write_netcdf_file(rarray<int,2> number_of_ants_on_table, std::string filename, int length, int numDataStep, std::string dataName);

#endif /* writeNetCDF_hpp */
