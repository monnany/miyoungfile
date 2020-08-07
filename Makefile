all: build

build:
	clang++ -o homework homework.cpp 

clean:
	rm -rf homework *.o *.dSYM
