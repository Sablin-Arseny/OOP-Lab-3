#include "iostream"
#include "string"

using namespace std;

class Step {
public:
    // Конструкторы
    Step();
    Step(string &name);
    Step(const Step &step);

    // Сеттеры и геттеры
    string getName() const;
    void setName(string &name);

    // Идентификаторы
    virtual bool isAction();
    virtual bool isIngredient();

protected:
    string _name;
};

