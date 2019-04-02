# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

final: main.o UtPod.o song.o
	g++ -o test main.o UtPod.o song.o
main.o: main.cpp UtPod.h Song.h
	g++ -c main.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c UtPod.cpp
song.o: Song.cpp Song.h
	g++ -c Song.cpp