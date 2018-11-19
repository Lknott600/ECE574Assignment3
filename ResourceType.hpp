/**
 * Name: ResourceType.hpp
 * Author: Evan Weiler
 * Description: Type to house properties about each resource type
 */

#include <memory>
#include "Operation.hpp"

class ResourceType {
private:
   std::string type;
   std::vector<float> probabilitySum;
   std::vector<Operation*> operations;

public:
   ResourceType(std::string name);
   void addOperation(Operation* op);
   void calcProbability(int latency);
};

ResourceType::ResourceType(std::string name) {
   type = name;
}

void ResourceType::addOperation(Operation* op) {
   operations.push_back(op);
}

void ResourceType::calcProbability(int latency) {
   float runningSum;
   for(auto operation: operations) {
      for(int i = 0; i < latency; i++) {
         runningSum += operation->getProbabilities().at(i);
      }
      probabilitySum.push_back(runningSum);
      runningSum = 0;
   }
}