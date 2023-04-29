all: compile

compile:
	g++ -std=c++11 ttt.cpp ttt_functions.cpp -o prog

rm:
	rm prog