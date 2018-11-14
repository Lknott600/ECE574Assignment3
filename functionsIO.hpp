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

vector<Variable> inputFileToVariables(string fileName);
void outputFileCreate(vector<Variable> allVariables, string outFile);
#endif
