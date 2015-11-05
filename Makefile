
#Enables C++11 
PATH := /usr/um/gcc-4.7.0/bin:$(PATH) 
LD_LIBRARY_PATH := /usr/um/gcc-4.7.0/lib64 
LD_RUN_PATH := /usr/um/gcc-4.7.0/lib64 

#Default Flags 
FLAGS = -Wall -Wextra -pedantic -Wvla -std=c++11 -lstdc++

# make release - will compile "all" with $(FLAGS) and the O3 flag 
release: FLAGS += -O3  
release: all 

# make debug - will compile "all" with $(FLAGS) and the g flag 
debug: FLAGS += -g 
debug: all 

# all: p1.cpp queue.cpp queue.h ioput.h ioput.cpp 
#     g++ $(FLAGS) p1.cpp queue.cpp queue.h ioput.h ioput.cpp -o p1 

# Make sure to compile object files with the -c flag 

all: 
	g++ $(FLAGS)  -I ~/Desktop/FALL15/Research/Simulation/Simulation/eigen-eigen-c58038c56923/ CutbySphere.cpp BCC.cpp ConvertToCartesianFromSpheric.cpp S1_BuildSimulationTipArea.cpp S2_FindSOI.cpp GetRin1Dir.cpp GetRin3Dir.cpp main.cpp -o main


GetRin1Dir: GetRin1Dir.cpp GetRin1Dir.h
	g++ $(FLAGS)  -I ~/Desktop/FALL15/Research/Simulation/Simulation/eigen-eigen-c58038c56923/ GetRin1Dir.cpp -c GetRin1Dir.cpp

GetRin3Dir: GetRin3Dir.cpp GetRin3Dir.h
	g++ $(FLAGS)  -I ~/Desktop/FALL15/Research/Simulation/Simulation/eigen-eigen-c58038c56923/ GetRin3Dir.cpp -c GetRin3Dir.cpp
	# make clean - remove .o files.  You can modify it to remove whatever 

ConvertToCartesianFromSpheric: ConvertToCartesianFromSpheric.cpp ConvertToCartesianFromSpheric.h
	g++ $(FLAGS) ConvertToCartesianFromSpheric.cpp -c ConvertToCartesianFromSpheric.cpp

bcc:
	g++ $(FLAGS) BuildBCC.cpp -o bcc

CutbySphere:
	g++ $(FLAGS)  -I ~/Desktop/FALL15/Research/Simulation/Simulation/eigen-eigen-c58038c56923/ CutbySphere.cpp -c CutbySphere.cpp

clean:
	\rm bcc
