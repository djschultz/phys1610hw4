// phys1610hw3

 #include "writeNetCDF.hpp"
 #include <iostream>
 #include <rarray>
 #include <rarrayio>
 #include <fstream>
 #include <netcdf>
 #include <vector>

 void define_netcdf_file(std::string filename, int length, std::string dataName){
     netCDF::NcFile dataFile(filename, netCDF::NcFile::replace); // define the netCDF file
     // Define the dimensions of the file
     netCDF::NcDim tDim = dataFile.addDim("t",NC_UNLIMITED);
     netCDF::NcDim xDim = dataFile.addDim("x", length);   
     netCDF::NcDim yDim = dataFile.addDim("y", length);

     // Define the variable for the ants data
     std::vector<netCDF::NcDim> dims(3);
     dims[0] = tDim;
     dims[1] = xDim;
     dims[2] = yDim;
     
     netCDF::NcVar antsVar = dataFile.addVar(dataName, netCDF::ncInt, dims); // tell the file the variable's name and dimensions

}

void write_netcdf_file(rarray<int,2> number_of_ants_on_table, std::string filename, int length, int numDataSet, std::string dataName){
     netCDF::NcFile dataFile(filename, netCDF::NcFile::write); // open the netCDf file in write mode
     netCDF::NcVar antsVar = dataFile.getVar(dataName); // get teh variable info from the netCDf file
     antsVar.putVar({(size_t) numDataSet, 0, 0}, {1, length, length}, number_of_ants_on_table.data()); // write to the NetCDF file in a certain layer given by numDataSet
}
