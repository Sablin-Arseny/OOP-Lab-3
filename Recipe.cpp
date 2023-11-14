#include "Recipe.h"

Recipe::Recipe(const Ingredient * ingredient) {
    recipe.push((Step*)ingredient);
}

void Recipe::add(const Step *step) {
    if (step->identify() == ingredient || step->identify() == action){
        recipe.push((Step*)step);
    }
}

bool Recipe::hasMistakes() const {
    if (this->isEmpty()){
        return true;
    }
    if (this->getStep()->identify() == action){
        return true;
    }
    if (recipe.size() == 1 && this->getStep()->identify() == ingredient){
        return true;
    }
    if (this->recipe.back()->identify() == ingredient){
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
        recipeCopy.nextStep();
    }
    return false;
}

bool Recipe::isEmpty() const {
    return recipe.empty();
}

void Recipe::nextStep() {
    recipe.pop();
}

void Recipe::popFirstStep() {
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

void Recipe::showStep() const {
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

void Recipe::showRecipe() const {
    if (!this->isEmpty()){
        Recipe recipeCopy = Recipe(*this);
        while(!recipeCopy.isEmpty()){
            recipeCopy.showStep();
            recipeCopy.nextStep();
        }
    } else{
        cout << "Empty recipe" << endl;
    }
}