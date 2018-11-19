#include <stdio.h>
#include <vector>
#include <algorithm>
#include "Operation.hpp"

void schedule_ASAP(std::vector<Operation> allOperations);
void schedule_ALAP(std::vector<Operation> allOperations, int latency);
void computeProbabilities(std::vector<Operation> allOperations, int latency);
void computeTypeDistributions(std::vector<Operation> allOperations, int latency);

void schedule_ASAP(std::vector<Operation> allOperations) {
    for (Operation op : allOperations) {
        if (!(op.getPredecessors().size() == 0))
            op.setAsapTime(1);
        else
            op.setAsapTime(std::max(op.getPredecessors().at(0)->getAsapTime(), op.getPredecessors().at(1)->getAsapTime()));
    }
}

void schedule_ALAP(std::vector<Operation> allOperations, int latency) {
    for (Operation op : allOperations) {
        if (!(op.getPredecessors().size() == 0))
            op.setAlapTime(latency);
        else
            op.setAlapTime(latency - op.getSuccessors().at(0)->getAlapTime());
    }
}

void computeProbabilities(std::vector<Operation> allOperations, int latency) {
    for (Operation op : allOperations) {
        op.getProbabilities().resize(latency + 1); //skip index 0 for purposes of timestamping
    }
    
    for (Operation op : allOperations) {
        for (int i = 1; i <= latency; i++) {
            if (i >= op.getAsapTime() && i <= op.getAlapTime()) {
                op.addProbability(1/float(op.getAlapTime() - op.getAsapTime() + 1), i);
            }
        }
    }
}

void computeTypeDistributions(std::vector<Operation> allOperations, int latency) {
    std::vector<Operation> uniqueOperations; //FIXME: make list of unique operations for circuit
    
    for (Operation op : allOperations) {
        if (!(std::find(uniqueOperations.begin(), uniqueOperations.end(), op.getOperation()) != uniqueOperations.end()))
            uniqueOperations.push_back(op);
    }
    //FIXME: may need to clear all fields except name of operation since all we care is the unique operation types using
    for (int ts = 1; ts <= latency; ++ts) { //ts means timestep
        for (Operation uOp : uniqueOperations) {
            for (Operation op : allOperations) {
                if (uOp.getOperation().compare(op.getOperation()))
                    uOp.addToProbabilityAtTimeStamp(op.getProbabilities().at(ts), ts);
            }
        }
    }
}

