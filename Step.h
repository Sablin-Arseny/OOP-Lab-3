#include "iostream"

using namespace std;

class Step {
public:
    void setName(string &name);
    string getName() const;

    Step();
    Step(string &name);
    Step(const Step &step);

    virtual bool isAction();
    virtual bool isIngredient();

protected:
    string _name;
};

