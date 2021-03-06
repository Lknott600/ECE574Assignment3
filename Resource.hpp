#ifndef Resource_hpp
#define Resource_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class Resource {
private:
    std::string operation;
    std::vector<float> sumOfProbsForTimeStep;
    
public:
    Resource() {
        this->operation = "undefined";
    }
    
    Resource(std::string name)  {
        this->name = name;
    }
    std::string getOperation() const {
        return this->operation;
    }
}

#endif /* Resource_hpp */
