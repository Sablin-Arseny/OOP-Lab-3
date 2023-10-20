#include "Ingredient.h"

// По умолчанию
Ingredient::Ingredient(){
    _name = "";
    _measureUnit = "";
    _amount = 0;
}

// Инициализация
Ingredient::Ingredient(string &name, string &measureUnit, double amount){
    setName(name);
    setMeasureUnit(measureUnit);
    setAmount(amount);
}

// Копирование
Ingredient::Ingredient(const Ingredient &ingredient){
    _name = ingredient.getName();
    _measureUnit = ingredient.getMeasureUnit();
    setAmount(ingredient.getAmount());
}

void Ingredient::setMeasureUnit(string &measureUnit){
    _measureUnit = measureUnit;
}

void Ingredient::setAmount(double amount){
    if (amount < 0){
        _amount = 0;
    }
    else{
        _amount = amount;
    }
}

string Ingredient::getMeasureUnit() const{
    return _measureUnit;
}

double Ingredient::getAmount() const{
    return _amount;
}

bool Ingredient::isIngredient() {
    return true;
}
