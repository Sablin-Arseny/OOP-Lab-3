#include "iostream"
#include "string"
#include "Action.h"

using namespace std;

class Ingredient: public Step{

public:
    // Конструкторы
    Ingredient();
    Ingredient(string &name, string &measureUnit, double amount);
    Ingredient(const Ingredient &ingredient);

    // Сеттеры
    void setMeasureUnit(string &measureUnit);
    void setAmount(double amount);

    // Геттеры
    string getMeasureUnit() const;
    double getAmount() const;

    // Идентификатор
    virtual bool isIngredient();

private:
    string _measureUnit;
    double _amount;
};
