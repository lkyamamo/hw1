all: ulliststr_test


ulliststr_test: ulliststr_test.cpp ulliststr.o 
	g++ -g -Wall $^ -o $@

ulliststr.o: ulliststr.cpp ulliststr.h
	g++ -g -Wall -c $< -o $@
