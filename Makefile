PP = g++
EXEC = ./tp02
TMPOUT=main.testresult
CFLAGS := -g -Wall -O3 -std=c++11
INC := -I include/ -I third_party/

build: src/main.cpp include/store.h src/store.cpp src/edge.cpp include/edge.h
	${PP} $(INC) -c src/main.cpp src/store.cpp src/edge.cpp
	${PP} $(INC) -o main main.o store.o edge.o

run: clean build
	./main < test/default.txt 

debug:
	${PP} main.cpp $(INC) -o test

clean:
	rm -rf *o main

tests: build
	@bash run_tests.sh ./main $(TMPOUT)