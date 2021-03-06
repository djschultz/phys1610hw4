// antsontable.cc
//
// Simulation of ants walking on a table. The table is subdivided into
// squares. A number of ants is initially put on the table, divided as
// evenly as possible over the squares.  Ants can move to a
// neighbouring square or stay put at every time step.  How many of a
// square's ants move in each of the 9 different directions is random
// (using the C++ random library).  Ants can fall of the edges of the
// table. The program prints the number of ants left on the table
// after every time step, as well as the minimum number of ants on any
// square and the maximum.
//
// This is the code for assignment 2 for the scientific computing course
// PHY1610H given in the Winter of 2020.
//
// Compile with:
//
//     g++ -std=c++14 -O3 -march=native -o antsontable antsontable.cc
//
// On the clusters, it will be necessary to load the "gcc" module first.
//
// Run with
//
//     ./antsontable > output.dat
//
// This saves the output to the file output.dat instead of writing it to
// screen.
//
// Ramses van Zon, SciNet, University of Toronto
// 2019-2020

#include <iostream>
#include <rarray>
#include <netcdf>
#include "partition.hpp"
#include "vectorization.hpp"
#include "ants.hpp"
#include "timeEvolve.hpp"
#include "report.hpp"
#include "writeText.hpp"
#include "writeBinary.hpp"
#include "writeNetCDF.hpp"
#include <random>

// There are (3 in the i direction)x(3 in the j direction)=9 possible moves
const int nmoves = 9;
const int moves[nmoves][2] = {{-1,-1},{-1,0},{-1,1}, {0,-1}, {0,0}, {0,1}, {1,-1}, {1,0}, {1,1}};

// Create global variables for the random seed and the engine, to be read by the partitioning function
size_t seed;
std::mt19937 engine;

// Main driver function of antsontable.cc

int main(int argc, const char * argv[])
{
    // ====================== assign  command line arguments  ==================== //
    std::string writeOption = argv[1]; // either -r, -b, or -n, determining a .rat, .bin, or .nc file
    std::string filename = argv[2]; // the filename of the .rat, .bin, or .nc file
    int outputInc = atoi(argv[3]); // this is the distasnce between consecutice outputs
    int length = atoi(argv[4]);
    int total_ants = atoi(argv[5]);
    int ntimesteps = atoi( argv[6]);
    size_t seed = atoi(argv[7]);
    // ===================== define arrays  ================== //
    
    // work arrays; these are linearized two-dimensional arrays
    rarray<int,2> number_of_ants_on_table(length,length);   // distribution of ants on the table over squares.
    rarray<int,2> new_number_of_ants_on_table(length,length); // auxiliary array used in time step to hold the new distribution of ants
    rarray<int,1> partition(nmoves);                 // used to determine how many ants move in which direction in a time step

    // ===================== initialize simulation ================== //
   
    placeAnts(length, total_ants, number_of_ants_on_table); // place ants on the table
    engine = std::mt19937(seed); // set the random seed for the time evolution of the ants moving around
        
    //Initialize antData array
    //the antData contains the minimum number of ants, maximum number of ants, and total number of ants as its zeroth, first, and second element respectively.
    rarray<int,1> antData(3);
    antData[0] = total_ants;
    antData[1] = 0;
    antData[2] = 0;
    
    //Count how many total ants there are on the table. This total number is put into antData[2].
    countAnts(length, antData, number_of_ants_on_table);
    
    // ===================== start simulation ================== //
    
    // report
    report(0,antData);
    // number of data sets we will write to the data file
    int dataSetNum = ntimesteps/outputInc;
    

    // Create a NetCDF file, but only if we have the -n flag
    std::string netCDFDataName = "ants";
    if(writeOption.compare("-n")==0){
    define_netcdf_file(filename, length, netCDFDataName); // define netCDF file
    }
    
    // run time steps
    for (int timestep = 0; timestep < ntimesteps; timestep++) {
        // Reset antData array
        antData[0] = total_ants;
        antData[1] = 0;
        antData[2] = 0;

        if(timestep%outputInc == 0){
            if(writeOption.compare("-r")==0){
               write_text_file(number_of_ants_on_table, filename); // write to the text file if -r flag entered
            }
            if(writeOption.compare("-b")==0){
                write_bin_file(number_of_ants_on_table, filename, length); // write to the binary file if -b flag entered
            } 
            if(writeOption.compare("-n")==0){
                write_netcdf_file(number_of_ants_on_table, filename, length, timestep/outputInc, netCDFDataName); // write to the netCDf file if the -n flag entered
           } 
        }
       // Perform a time step of the ants' movement.
       incrementTime(length, nmoves, timestep, antData, number_of_ants_on_table, new_number_of_ants_on_table, partition, moves);
    }
    return 0;
}
