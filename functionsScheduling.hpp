#include <stdio.h>
#include <vector>
#include <algorithm>
#include "Operation.hpp"

void schedule_ASAP(std::vector<Operation> &allOperations);
void schedule_ALAP(std::vector<Operation> &allOperations, int latency);
void computeProbabilities(std::vector<Operation> &allOperations, int latency);
void computeTypeDistributions(std::vector<Operation> &allOperations, int latency);

void schedule_ASAP(std::vector<Operation> &allOperations) {
    int maxAsap = 0;
    int associatedDelay = 0;
    for (unsigned int i = 0; i < allOperations.size(); ++i) {
        if (allOperations.at(i).getPredecessors().size() == 0)
            allOperations.at(i).setAsapTime(1);
        else {
            for (int j = 0; j < allOperations.at(i).getPredecessors().size(); j++) {
                if (allOperations.at(i).getPredecessors().at(j)->getAsapTime() > maxAsap) {
                    maxAsap = allOperations.at(i).getPredecessors().at(j)->getAsapTime();
                    associatedDelay = allOperations.at(i).getPredecessors().at(j)->getDelay();
                }
            }
            allOperations.at(i).setAsapTime(maxAsap + associatedDelay);
        }
    }
}

void schedule_ALAP(std::vector<Operation> &allOperations, int latency) {
    int currMin = 777; //arbitrarily large number
    int associatedDelay = 0;
    for (int i = (int)allOperations.size() - 1; i >= 0; --i) {
        if (allOperations.at(i).getSuccessors().size() == 0)
            allOperations.at(i).setAlapTime(latency);
        else {
            for (int j = 0; j < allOperations.at(i).getSuccessors().size(); j++) {
                if (allOperations.at(i).getSuccessors().at(j)->getAlapTime() < currMin) {
                    currMin = allOperations.at(i).getSuccessors().at(j)->getAlapTime();
                    associatedDelay = allOperations.at(i).getSuccessors().at(j)->getDelay();
                }
            }
            allOperations.at(i).setAlapTime(currMin - associatedDelay);
        }
    }
}

void computeProbabilities(std::vector<Operation> &allOperations, int latency) {
    for (unsigned int i = 0; i < allOperations.size(); i++) {
        for (unsigned int j = 0; j <= latency; j++) { //do <= or equal to to have a index for one to latency (i.e each time stamp), we'll just ignore the zero index
            if (i >= allOperations.at(i).getAsapTime() && i <= allOperations.at(i).getAlapTime())
                allOperations.at(i).addProbability(1/float(allOperations.at(i).getAlapTime() - allOperations.at(i).getAsapTime() + 1));
            else
                allOperations.at(i).addProbability(0.0);
        }
    }
}

//void computeTypeDistributions(std::vector<Operation> &allOperations, int latency) {
//    std::vector<Operation> uniqueOperations; //FIXME: make list of unique operations for circuit
//
//    for (Operation op : allOperations) {
//        if (!(std::find(uniqueOperations.begin(), uniqueOperations.end(), op.getOperation()) != uniqueOperations.end()))
//            uniqueOperations.push_back(op);
//    }
//    //FIXME: may need to clear all fields except name of operation since all we care is the unique operation types using
//    for (int ts = 1; ts <= latency; ++ts) { //ts means timestep
//        for (Operation uOp : uniqueOperations) {
//            for (Operation op : allOperations) {
//                if (uOp.getOperation().compare(op.getOperation()))
//                    uOp.addToProbabilityAtTimeStamp(op.getProbabilities().at(ts), ts);
//            }
//        }
//    }
//}

