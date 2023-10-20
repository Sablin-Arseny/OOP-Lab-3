#include "iostream"
#include "string"

using namespace std;

class Step {
public:
    Step();
    Step(string &name);
    Step(const Step &step);

    void setName(string &name);
    string getName() const;

    // Идентификаторы
    virtual bool isAction();
    virtual bool isIngredient();

protected:
    string _name;
};

