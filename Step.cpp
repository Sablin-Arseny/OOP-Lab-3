#include "Step.h"

Step::Step(){
    _name = "";
}

Step::Step(string &name){
    setName(name);
}

Step::Step(const Step &step){
    _name = step._name;
}

void Step::setName(string &name) {
    _name = name;
}

string Step::getName() const {
    return _name;
}

bool Step::isIngredient() {
    return false;
}

bool Step::isAction() {
    return false;
}