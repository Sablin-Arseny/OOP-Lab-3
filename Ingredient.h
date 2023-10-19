#include "Step.h"

using namespace std;

class Ingredient: public Step{

public:
    // Конструкторы
    Ingredient();
    Ingredient(string &name, string &measureUnit, double amount);
    Ingredient(Ingredient const &ingredient);

    // Геттеры
    string getMeasureUnit() const;
    double getAmount() const;

    // Сеттеры
    void setMeasureUnit(string &measureUnit);
    void setAmount(double amount);

private:
    string _measureUnit;
    double _amount;
};
