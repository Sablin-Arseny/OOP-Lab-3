#include "Action.h"

class Ingredient: public Step{

public:
    // Конструкторы
    Ingredient();
    Ingredient(string &name, string &measureUnit, double amount);
    Ingredient(const Ingredient &ingredient);

    // Геттеры
    string getMeasureUnit() const;
    double getAmount() const;

    // Сеттеры
    void setMeasureUnit(string &measureUnit);
    void setAmount(double amount);

    virtual bool isIngredient();

private:
    string _measureUnit;
    double _amount;
};
