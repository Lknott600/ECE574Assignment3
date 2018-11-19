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
	std::vector<Operation*> predecessor; //All Operation nodes that are predecessors 
	std::vector<Operation*> successor;	//All Operation nodes that are successors

public:
	Operation() { //default constructor
		std::string operation = "DUMMY";
		int delay = -1;	
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

	std::vector<Operation *> getPredecessors() {
		return this->predecessor;
	}

	std::vector<Operation *> getSuccessors() {
		return this->successor;
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
	
	void setPredecessor(Operation *predOp) {
		this->predecessor.push_back(predOp);
	}

	void setSuccessor(Operation *succOp) {
		this->successor.push_back(succOp);
	}

};
#endif
