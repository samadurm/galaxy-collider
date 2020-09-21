INC=./includes

all:
	nvcc -o collider -I$(INC) src/main.cu -O3 --compiler-options -Wall
