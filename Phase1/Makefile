all: final

final: memoryclass.o make_map.o conv_binary.o machine_conv.o code_conv.o phase1.o
	g++ memoryclass.o make_map.o conv_binary.o machine_conv.o code_conv.o phase1.o -o final

machine_conv.o: machine_conv.cpp
	g++ -c machine_conv.cpp

conv_binary.o: conv_binary.cpp
	g++ -c conv_binary.cpp

make_map.o: make_map.cpp
	g++ -c make_map.cpp

code_conv.o: code_conv.cpp
	g++ -c code_conv.cpp

phase1.o: phase1.cpp
	g++ -c phase1.cpp

memoryclass.o: memoryclass.cpp
	g++ -c memoryclass.cpp	


		
clean:
	rm *o final
