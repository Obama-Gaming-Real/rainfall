all:
	g++ rainfall.cpp -o rain -static -static-libgcc -static-libstdc++ -fpermissive -std=c++11 -pedantic