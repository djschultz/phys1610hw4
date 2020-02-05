#Makefile for antsontable.cpp

#Specify what compiler we will use
CXX = g++

#Specify locations of the netcdf libraries
NETCDF_LIB = ${SCINET_NETCDF_ROOT}/lib
NETCDF_INC = ${SCINET_NETCDF_ROOT}/include

#Macro for the flags that we will use to compile the code. 
flags = -std=c++14 -O3 -march=native

#Link all of the out files and combine into an executable called antsontable
antsontable: antsontable.o ants.o partition.o vectorization.o timeEvolve.o report.o writeText.o writeBinary.o writeNetCDF.o
	$(CXX) $(flags) -o antsontable antsontable.o ants.o partition.o vectorization.o timeEvolve.o report.o writeText.o writeBinary.o -L$(NETCDF_LIB) writeNetCDF.o -lnetcdf_c++4

#Individually compile all of the modules without making an executable
antsontable.o: antsontable.cpp ants.hpp partition.hpp vectorization.hpp timeEvolve.hpp report.hpp
	$(CXX) $(flags) -c -o antsontable.o antsontable.cpp

ants.o: ants.cpp vectorization.hpp
	$(CXX) $(flags) -c -o ants.o ants.cpp

partition.o: partition.cpp
	$(CXX) $(flags) -c -o partition.o partition.cpp

vectorization.o: vectorization.cpp
	$(CXX) $(flags) -c -o vectorization.o vectorization.cpp

timeEvolve.o: timeEvolve.cpp partition.hpp report.hpp ants.hpp vectorization.hpp
	$(CXX) $(flags) -c -o timeEvolve.o timeEvolve.cpp 

report.o: report.cpp
	$(CXX) $(flags) -c -o report.o report.cpp

writeText.o: writeText.cpp
	$(CXX) $(flags) -c -o writeText.o writeText.cpp

writeBinary.o: writeBinary.cpp
	$(CXX) $(flags) -c -o writeBinary.o writeBinary.cpp

writeNetCDF.o: writeNetCDF.cpp
	$(CXX) -I$(NETCDF_INC) -c -o writeNetCDF.o writeNetCDF.cpp

clean: 
	rm -f antsontable.o ants.o partition.o vectorization.o timeEvolve.o report.o antsontable output.dat writeText.o writeBinary.o writeNetCDF.cpp
	
