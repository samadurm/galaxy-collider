INC=./includes

all:
	nvcc -o collider src/main.cu src/planet.cpp -I$(INC) --compiler-options -std=c++11

