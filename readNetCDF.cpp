// phys1610hw3

 #include "readNetCDF.hpp"
 #include <iostream>
 #include <rarray>
 #include <rarrayio>
 #include <fstream>
 #include <netcdf>
 #include <vector>
 #include "ants.hpp"
 #include "report.hpp"

 void read_netcdf_file(std::string filename, int numSteps, int length){
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
     
     int total_ants = 40000;
     rarray<int,1> antData(3);
     antData[0] = total_ants;
     antData[1] = 0;
     antData[2] = 0;
 
     rarray<int,2> number_of_ants_on_table(nx,ny);
     
     netCDF::NcVar antsVar = dataFile.getVar("ants");
     for(size_t i = 0; i < numSteps; i ++){
         antsVar.getVar({(size_t) i , 0,0}, {1,nx, ny}, number_of_ants_on_table.data());
         countAnts(length, antData, number_of_ants_on_table);
         report(1+i*1000, antData);
         antData[0] = total_ants;
         antData[1] = 0;
         antData[2] = 0;

     }
   
 }
