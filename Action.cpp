#include "Action.h"

// Конструкторы
// По умолчанию
Action::Action(){
    _name = "";
    _durationMinute = 0;
}
// Инициализация
Action::Action(string &name, double durationMinute){
    setName(name);
    setDurationMinute(durationMinute);
}
// Копирование
Action::Action(Action const &action){
    _name = action.getName();
    setDurationMinute(action.getDurationMinute());
}

// Геттеры
double Action::getDurationMinute() const{
    return _durationMinute;
}

// Сеттеры
void Action::setDurationMinute(double durationMinute){
    if (durationMinute < 0){
        _durationMinute = 0;
    }
    else {
        _durationMinute = durationMinute;
    }
}

bool Action::isAction() {
    return true;
}