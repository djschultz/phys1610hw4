// phys1610hw3

 #include "writeNetCDF.hpp"
 #include <iostream>
 #include <rarray>
 #include <rarrayio>
 #include <fstream>
 #include <netcdf>
 #include <vector>

 netCDF::NcVar create_netcdf_file(std::string filename, int dim1, int dim2, netCDF::NcFile& dataFile){

     
     // Define the dimensions of the file
     netCDF::NcDim tDim = dataFile.addDim("t",NC_UNLIMITED);
     netCDF::NcDim xDim = dataFile.addDim("x",dim1);   
     netCDF::NcDim yDim = dataFile.addDim("y",dim2);

     // Define the variable for the ants data
     std::vector<netCDF::NcDim> dims(3);
     dims[0] = tDim;
     dims[1] = xDim;
     dims[2] = yDim;

     netCDF::NcVar antsVar = dataFile.addVar("ants", netCDF::ncInt, dims);

     return antsVar;

}

void write_netcdf_file(rarray<int,2> myrarray, netCDF::NcVar antsVar, int dim1, int dim2, int numDataSet, netCDF::NcFile& file){

     antsVar.putVar({(size_t) numDataSet, 0, 0}, {1, dim1, dim2}, myrarray.data());
//	antsVar.putVar(myrarray.data());
}
