#include "Step.h"

using namespace std;

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

private:
    double _durationMinute;
};