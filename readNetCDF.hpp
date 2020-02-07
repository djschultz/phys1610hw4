//phys1610hw3

#ifndef readNetCDF__hpp
#define readNetCDF__hpp

#include <stdio.h>
#include <rarray>

/// @brief function to read the conents from a netcdf file and print the contents to the console
/// @param filename the name of the file to be read from
/// @param numSteps the number of arrays we will read from the netcdf file
/// @param length the side length of one of the 2D arrays we are reading
/// @param initAnts the initial number of ants in the simulation
/// @param outputInc the number of timesteps in between consecutive outputs
void read_netcdf_file(std::string filename, int numSteps, int length, int initAnts, int outputInc);

#endif /* readNetCDF_hpp */
