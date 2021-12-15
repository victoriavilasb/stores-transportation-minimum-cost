PP = g++
EXEC = ./tp02
TMPOUT=main.testresult
CFLAGS := -g -Wall -O3 -std=c++11

build: src/main.cpp include/store.hpp src/store.cpp
	${PP} -c src/main.cpp src/store.cpp
	${PP} -o main main.o store.o

run: clean build
	./main < test/default.txt 

debug:
	${PP} main.cpp -o test

clean:
	rm -rf *o main

tests: build
	@bash run_tests.sh ./main $(TMPOUT)