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

 void read_netcdf_file(std::string filename, int numSteps, int length, int initAnts, int outputInc){
     netCDF::NcFile dataFile(filename, netCDF::NcFile::read); // open the netcdf file to be read
     netCDF::NcDim tDim = dataFile.getDim("t"); // get the dimensions of the dataset
     netCDF::NcDim xDim = dataFile.getDim("x");
     netCDF::NcDim yDim = dataFile.getDim("y");   

     int nt = tDim.getSize(); // put the dimensions of the data into integer values
     int nx = xDim.getSize();
     int ny = yDim.getSize();
     
     int total_ants = initAnts; // set the total_ants to be initAnts
     rarray<int,1> antData(3); // make an array to  store the min, max, and total ant information 
     antData[0] = total_ants;
     antData[1] = 0;
     antData[2] = 0;
 
     rarray<int,2> number_of_ants_on_table(nx,ny); // rarray to store the number of ants on the table
     
     netCDF::NcVar antsVar = dataFile.getVar("ants"); 

     for(size_t i = 0; i < numSteps; i ++){
         antsVar.getVar({(size_t) i , 0,0}, {1,nx, ny}, number_of_ants_on_table.data()); // put a slice of the netcdf file into an rarray
         countAnts(length, antData, number_of_ants_on_table); // count the ants
         report(i*outputInc, antData); // print the ants to the screen
         antData[0] = total_ants;
         antData[1] = 0;
         antData[2] = 0;

     }
   
 }
