#include "Recipe.h"

Recipe::Recipe(){
    _root = new node;

    _root->_left = nullptr;
    _root->_right = nullptr;
};

Recipe::Recipe(const Step *step) {
    _root = new node;

    _root->_step = new Step();
    _root->_step = (Step *) step;

    _root->_right = nullptr;
    _root->_left = nullptr;
}

Step * Recipe::getStep() const{
    return _root->_step;
}

void Recipe::add(const Step *step){
    node *start = _root;

    while (_root->_right or _root->_left){
        this->next();
    }

    node *newStep = new node;
    newStep->_step = (Step *) step;
    _root->_right = newStep;
    _root = start;
    if (!_root->_step){
        this->next();
    }
}

void Recipe::next(){
    if (_root->_left){
        _root = _root->_left;
    }
    else if(_root->_right){
        _root = _root->_right;
    }
    else{
        _root = nullptr;
    }
}

void Recipe::pop(){
    node *pointer = _root;
    node *prevPointer = pointer;
    if (!pointer->_left and !pointer->_right){
        _root->_step = nullptr;
        _root->_right = nullptr;
        _root->_left = nullptr;
    }
    else{
        while(pointer->_left or pointer->_right){
            if(pointer->_right){
                prevPointer = pointer;
                pointer = pointer->_right;
            }
            if(pointer->_left){
                prevPointer = pointer;
                pointer = pointer->_left;
            }
        }
        prevPointer->_left = nullptr;
        prevPointer->_right = nullptr;
        delete pointer;
    }
}

bool Recipe::stepIsIngredient() const{
    return _root->_step->isIngredient();
}

bool Recipe::stepIsAction() const{
    return _root->_step->isAction();
}

bool Recipe::isEmpty() const{
    if (_root->_step){
        return false;
    }
    else{
        return true;
    }
}

void Recipe::showStep(){
    if (!this->isEmpty()){
        if(_root->_step->isIngredient()){
            cout << ((Ingredient*)_root->_step)->getName() << " ";
            cout << ((Ingredient*)_root->_step)->getAmount() << " ";
            cout << ((Ingredient*)_root->_step)->getMeasureUnit() << endl;
        }
        else if(_root->_step->isAction()){
            cout << ((Action*)_root->_step)->getName() << " ";
            cout <<((Action*)_root->_step)->getDurationMinute() << " min" << endl;
        }
    }
    else{
        cout << "Empty step" << endl;
    }
}

void Recipe::showRecipe() {
    if (!this->isEmpty()){
        node *pointer = _root;
        while(_root) {
            this->showStep();
            this->next();
        }
        _root = pointer;
    }
    else{
        cout << "Empty recipe" << endl;
    }
}