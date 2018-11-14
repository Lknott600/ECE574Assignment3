#ifndef FUNCTIONSIO_HPP
#define FUNCTIONSIO_HPP

//For File IO
#include <iostream>
#include <fstream>
#include <sstream>
//Type declaration
#include <vector>
#include <string>
#include <algorithm>
//Header dependencies
#include "Variable.hpp"
#include "Operation.hpp"

using namespace std;

//File Input
vector<Variable> inputFileToVariables(string fileName, vector<Operation> *allOps);

vector<Variable> compileListOfVariables(string line, vector<Variable> allVariables,	string currType, 
	string bitWidth, string varNames, Variable tempVar, string delimiter, string currName,	int pos);

vector<Operation> compileListOfOperations(string line, vector<Variable> allVariables, vector<Operation> allOperations,
	vector<Variable> currOperand, string val, int count, bool validVar, bool signedFlag,
	int maxDatawidth, int flagExtendLocVar1, int flagExtendLocVar2, int operandCount,
	bool flagIncDec);


//File Output
void outputFileCreate(vector<Variable> allVariables, string outFile);


#endif
