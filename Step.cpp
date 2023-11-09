#include "Step.h"

Step::Step(){
    _name = "";
}

Step::Step(string &name){
    setName(name);
}

Step::Step(const Step &step){
    _name = step.getName();
}

void Step::setName(string &name) {
    _name = name;
}

string Step::getName() const {
    return _name;
}

StepType Step::identify() const{
    return StepType::step;
}