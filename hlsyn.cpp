/*
Name: Brendan Cassidy, Diego Alcantra, Evan Weiler, Logan Knott
Project: ECE 474/574 Project 3
Description:
This project creates an implementation of the Force Directed Schedule taking in the following
format for command line args:
hlsyn cFile latency(int) verilogFile(output.v)
*/
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Variable.hpp"
#include "functionsIO.hpp"
using namespace std;

int main(int argc, char *argv[]) {

	//if (argc != 3) {
	//	cout << "Usage: main inputFile outputFile" << endl;
	//	return EXIT_FAILURE;
	//}

	vector<Variable> allVariables;
	vector<Operation> allOperations;
	//IO, we must set up the writing of the variables to the outputs [Handled once AllVars returns]
	//Create vector of all Variables [Done with allVariables]
	//Map the Operations [Not Done]
	allVariables = inputFileToVariables(argv[1], &allOperations);
	
	//Send to the force directed scheduling.

	//writing to output file
	outputFileCreate(allVariables, argv[2]);
	
	return 0;
};
