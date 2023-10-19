#include "Recipe.h"

Recipe::Recipe(){
    _root = new node;

    _root->_left = nullptr;
    _root->_right = nullptr;
};

Recipe::Recipe(const Ingredient &ingredient) {
    _root = new node;

    _root->_ingredient = Ingredient(ingredient);
    _root->_right = nullptr;
    _root->_left = nullptr;
    _root->_isIngredient = true;
}

Recipe::Recipe(Recipe &recipe) {
    _root = new node;
    if (recipe.isIngredient()){
        _root->_ingredient = Ingredient(recipe._root->_ingredient);
    }
    else if (recipe.isAction()){
        _root->_action = Action(recipe._root->_action);
    }
    node *start = recipe._root;
    while (!recipe.isEmpty()){
        if (recipe.isIngredient()){
            this->add(recipe._root->_ingredient);
        }
        else if (recipe.isAction()){
            this->add(recipe._root->_action);
        }
        recipe.next();
    }
    recipe._root = start;
}

void Recipe::add(const Ingredient &ingredient){
    node *start = _root;

    while (_root->_right or _root->_left){
        this->next();
    }
    Ingredient newIngredient = Ingredient(ingredient);
    node *newStep = new node;
    newStep->_ingredient = newIngredient;
    newStep->_isIngredient = true;
    _root->_right = newStep;
    _root = start;
}

void Recipe::add(const Action &action){
    node *start = _root;

    while (_root->_right or _root->_left){
        this->next();
    }
    Action newAction = Action(action);
    node *newStep = new node;
    newStep->_action = newAction;
    newStep->_isIngredient = false;
    _root->_left = newStep;
    _root = start;
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

Ingredient Recipe::getIngredient(){
    return _root->_ingredient;
}

Action Recipe::getAction() {
    return _root->_action;
}

bool Recipe::isIngredient(){
    return _root->_isIngredient;
}

bool Recipe::isAction(){
    return !_root->_isIngredient;
}

void Recipe::showStep(){
    if(this->isIngredient()){
        cout << _root->_ingredient.getName() << " ";
        cout << _root->_ingredient.getAmount() << " ";
        cout << _root->_ingredient.getMeasureUnit() << endl;
    }
    else if(this->isAction()){
        cout << _root->_action.getName() << " ";
        cout << _root->_action.getDurationMinute() << " min" << endl;
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