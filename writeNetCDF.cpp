// phys1610hw3

#include "writeNetCDF.hpp"
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fstream>
#include <netcdf>
#include <vector>

void write_netcdf_file(int* myrarray, std::string filename, int dim1, int dim2){
    netCDF::NcFile dataFile(filename, netCDF::NcFile::replace);
    netCDF::NcDim xDim = dataFile.addDim("x",dim1);
    netCDF::NcDim yDim = dataFile.addDim("y",dim2);   
    
    std::vector<netCDF::NcDim> dims(2);
    dims[0] = xDim;
    dims[1] = yDim;
    
    netCDF::NcVar data = dataFile.addVar("data", netCDF::ncInt, dims);
    data.putVar(myrarray);
     
}

