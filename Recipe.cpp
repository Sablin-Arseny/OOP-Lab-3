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

//Recipe::Recipe(Recipe &recipe) {
//    _root = new node;
//    if (recipe.isIngredient()){
//        _root->_ingredient = Ingredient(recipe._root->_ingredient);
//    }
//    else if (recipe.isAction()){
//        _root->_action = Action(recipe._root->_action);
//    }
//    node *start = recipe._root;
//    while (!recipe.isEmpty()){
//        if (recipe.isIngredient()){
//            this->add(recipe._root->_ingredient);
//        }
//        else if (recipe.isAction()){
//            this->add(recipe._root->_action);
//        }
//        recipe.next();
//    }
//    recipe._root = start;
//}

void Recipe::add(Step *step){
    node *start = _root;

    while (_root->_right or _root->_left){
        this->next();
    }

    node *newStep = new node;
    newStep->_step = step;
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

Step * Recipe::getStep(){
    return _root->_step;
}

bool Recipe::stepIsIngredient(){
    return _root->_step->isIngredient();
}

bool Recipe::stepIsAction(){
    return _root->_step->isAction();
}

void Recipe::showStep(){
    if (_root){
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
        cout << "Empty recipe" << endl;
    }
}

void Recipe::showRecipe() {
    node *pointer = _root;
    while(_root) {
        this->showStep();
        this->next();
    }
    _root = pointer;
}

bool Recipe::isEmpty() {
    if (_root){
        return false;
    }
    else{
        return true;
    }
}

void Recipe::pop(){
    node *pointer = _root;
    node *prevPointer = pointer;
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