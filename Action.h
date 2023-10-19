#include "Step.h"

class Action: public Step{

public:
    // Конструкторы
    Action();
    Action(string &name, double durationMinute);
    Action(Action const &action);

    // Геттеры
    double getDurationMinute() const;

    // Сеттеры
    void setDurationMinute(double durationMinute);

    virtual bool isAction();

private:
    double _durationMinute;
};