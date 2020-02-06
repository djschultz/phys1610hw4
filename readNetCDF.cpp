// phys1610hw3

 #include "readNetCDF.hpp"
 #include <iostream>
 #include <rarray>
 #include <rarrayio>
 #include <fstream>
 #include <netcdf>
 #include <vector>

 void read_netcdf_file(std::string filename, int numSteps){
     netCDF::NcFile dataFile(filename, netCDF::NcFile::read);
     netCDF::NcDim tDim = dataFile.getDim("t");
     netCDF::NcDim xDim = dataFile.getDim("x");
     netCDF::NcDim yDim = dataFile.getDim("y");   
     std::vector<netCDF::NcDim> dims(3);

     dims[0] = tDim;
     dims[1] = xDim;
     dims[2] = yDim;
     int nt = tDim.getSize();
     int nx = xDim.getSize();
     int ny = yDim.getSize();
     
     rarray<int,2> p(nx,ny);
     
     netCDF::NcVar antsVar = dataFile.getVar("ants");
     for(size_t i = 0; i < numSteps; i ++){
         antsVar.getVar({(size_t) i , 0,0}, {1,nx, ny}, p.data());
         std::cout << p;
     }
   
 }
