#include "iostream"
#include "string"

using namespace std;

class Step {
public:
    void setName(string &name);
    string getName() const;

    Step();
    Step(string &name);
    Step(const Step &step);

    // Идентификаторы
    virtual bool isAction();
    virtual bool isIngredient();

    // Виртуальные

protected:
    string _name;
};

