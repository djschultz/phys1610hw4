// phys1610hw3

 #include "readNetCDF.hpp"
 #include <iostream>
 #include <rarray>
 #include <rarrayio>
 #include <fstream>
 #include <netcdf>
 #include <vector>

 void read_netcdf_file(int* myrarray, std::string filename){
     netCDF::NcFile dataFile(filename, netCDF::NcFile::read);
     netCDF::NcDim xDim = dataFile.getDim("x");
     netCDF::NcDim yDim = dataFile.getDim("y");   

     int nx = xDim.getSize();
     int ny = xDim.getSize();
     rarray<int,2> p(nx,ny);
     
     netCDF::NcVar data = dataFile.getVar("data");
     data.getVar(p.data());

     for(int i =0; i < nx; i++){
        for(int j = 0; j < ny; j++){
           std::cout << p[i][j] << " ";
        }
     }
 }
