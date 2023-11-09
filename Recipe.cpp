#include "Recipe.h"

Recipe::Recipe(const Ingredient * ingredient) {
    recipe.push((Step*)ingredient);
}

void Recipe::add(const Step *step) {
    if (step->identify() == ingredient || step->identify() == action){
        recipe.push((Step*)step);
    }
}

bool Recipe::hasMistakes() {
    if (this->isEmpty()){
        return true;
    }
    if (this->getStep()->identify() == action){
        return true;
    }
    if (recipe.size() == 1 && this->getStep()->identify() == ingredient){
        return true;
    }
    bool prevIsIngredient = false;
    Recipe recipeCopy = Recipe(*this);
    while (!recipeCopy.isEmpty()){
        if (recipeCopy.getStep()->identify() == ingredient){
            if (prevIsIngredient){
                return true;
            }
            prevIsIngredient = true;
        }
        else{
            prevIsIngredient = false;
        }
        recipeCopy.next();
    }
    return false;
}

bool Recipe::isEmpty() {
    return recipe.empty();
}

void Recipe::next() {
    recipe.pop();
}

void Recipe::pop() {
    recipe.pop();
}

Step *Recipe::getStep() const {
    if (!recipe.empty()){
        return recipe.front();
    }
    else{
        return nullptr;
    }
}

void Recipe::showStep() {
    if (!this->isEmpty()){
        if (this->getStep()->identify() == ingredient){
            cout << ((Ingredient*) this->getStep())->getName() << " ";
            cout << ((Ingredient*) this->getStep())->getAmount() << " ";
            cout << ((Ingredient*) this->getStep())->getMeasureUnit() << endl;
        }
        else if (this->getStep()->identify() == action){
            cout << ((Action*) this->getStep())->getName() << " ";
            cout <<((Action*) this->getStep())->getDurationMinute() << " min" << endl;
        }
        else{
            cout << "Empty step" << endl;
        }
    }
    else{
        cout << "Empty recipe" << endl;
    }
}

void Recipe::showRecipe() {
    if (!this->isEmpty()){
        Recipe recipeCopy = Recipe(*this);
        while(!recipeCopy.isEmpty()){ // переписать на конструктор копирования
            recipeCopy.showStep();
            recipeCopy.next();
        }
    } else{
        cout << "Empty recipe" << endl;
    }
}