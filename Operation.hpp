#ifndef OPERATION_HPP
#define OPERATION_HPP
#include <string>
#include <vector>
#include "Variable.hpp"

class Operation {
private:
	std::string operation;
	int delay;
	std::vector<Variable> inputs;
	Variable output;
	std::vector<Operation*> predecessor; //All Operation nodes that are predecessors 
	std::vector<Operation*> successor;	//All Operation nodes that are successors
    std::vector<float> probabilities; //in probabilities, the time that corresponds to that prob is the index in which it is in and the index is the timestep
    int asapTime;
    int alapTime;

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
    int getAsapTime() {
        return this->asapTime;
    }
    int getAlapTime() {
        return this->alapTime;
    }
    std::vector<float> getProbabilities() {
        return this->probabilities;
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
    void setAsapTime(int asapTime) {
        this->asapTime = asapTime;
    }
    void setAlapTime(int alapTime) {
        this->alapTime = alapTime;
    }
    void addProbability(float probability, int timeStamp) {
        this->probabilities.at(timeStamp) = probability;
    }
    void addToProbabilityAtTimeStamp(float probability, int timeStamp) {
        this->probabilities.at(timeStamp) = probability + this->probabilities.at(timeStamp);
    }

};
#endif
