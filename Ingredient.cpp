#include "Ingredient.h"

// По умолчанию
Ingredient::Ingredient(){
    _measureUnit = "";
    _amount = 0;
}
// Инициализация
Ingredient::Ingredient(string &name, string &measureUnit, double amount){
    _measureUnit = measureUnit;
    if (amount < 0){
        _amount = 0;
    }
    else{
        _amount = amount;
    }
}
// Копирование
Ingredient::Ingredient(Ingredient const &ingredient){
    _measureUnit = ingredient._measureUnit;
    _amount = ingredient._amount;
}

// Геттеры
string Ingredient::getMeasureUnit() const{
    return _measureUnit;
}
double Ingredient::getAmount() const{
    return _amount;
}

// Сеттеры
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
