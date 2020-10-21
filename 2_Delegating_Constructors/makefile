main: main.cpp
	g++ -o main.out main.cpp

main1: main1.cpp
	g++ -o main1.out main1.cpp

main2: main2.cpp
	g++ -o main2.out main2.cpp

main3: main3.cpp
	g++ -o main3.out main3.cpp

main4: main4.cpp
	g++ -o main4.out main4.cpp

all: main main1 main2 main3 main4

.PHONY: help clean

help:
	@cat help.txt

clean:
	@rm -f main*.out