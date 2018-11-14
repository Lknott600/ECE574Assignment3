#ifndef OPERATION_HPP
#define OPERATION_HPP
#include <string>
#include "Variable.hpp"

class Operation {
private:
	std::string operation;
	int delay;
	std::vector<Variable> inputs;
	Variable output;

public:
	Operation() { //default constructor
		this->delay = 0;
		this->operation = '@';
	}
	Operation(std::string operation, std::vector<Variable> inputs, Variable output) {
		this->operation = operation;
		this->delay = calcDelay(operation);
		this->inputs = inputs;
		this->output = output;
	}
	//getters
	std::string getOperation() const {
		return this->operation;
	}

	int getDelay() const {
		return this->delay;
	}

	std::vector<Variable> getInputs() {
		return this->inputs;
	}

	Variable getOutput() {
		return this->output;
	}

	//setters
	void setOperation(std::string operation) {
		this->operation = operation;
		this->delay = calcDelay(operation);
	}

	void setDelay(int delay) {
		this->delay = delay;
	}

	void setInputs(std::vector<Variable> inputs) {
		this->inputs = inputs;
	}

	void setAnInput(Variable input) {
		this->inputs.push_back(input);
	}

	void setOutput(Variable output) {
		this->output = output;
	}

	int calcDelay(std::string operation) {
		if (operation.compare("*") == 0)
			return 2;
		else if (operation.compare("/") == 0 || operation.compare("%") == 0)
			return 3;
		else
			return 1;
	}
	//Need to map operation to cycle count
};
#endif
