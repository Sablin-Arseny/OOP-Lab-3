#include "iostream"
#include "string"

using namespace std;

enum StepType {
    ingredient,
    action,
    step
};


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
    virtual StepType identify() const;

protected:
    string _name;
};

