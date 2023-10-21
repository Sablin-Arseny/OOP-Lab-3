#include "iostream"
#include "string"
#include "Step.h"

using namespace std;

class Action: public Step{

public:
    // Конструкторы
    Action();
    Action(string &name, double durationMinute);
    Action(const Action &action);

    // Геттеры
    double getDurationMinute() const;

    // Сеттеры
    void setDurationMinute(double durationMinute);

    // Идентификатор
    bool isAction() override;

private:
    double _durationMinute;
};