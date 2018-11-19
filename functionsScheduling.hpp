
#ifndef functionsScheduling_hpp
#define functionsScheduling_hpp

#include <stdio.h>
#include <vector>
#include <algorithm>
#include "Variable.hpp"
#include "Operation.hpp"

void schedule_ASAP(std::vector<Operation> allOperations);
void schedule_ALAP(std::vector<Operation> allOperations, int latency);
void computeProbabilities(std::vector<Operation> allOperations, int latency);
void computeTypeDistributions(std::vector<Operation> allOperations, int latency);

#endif /* functionsScheduling_hpp */
