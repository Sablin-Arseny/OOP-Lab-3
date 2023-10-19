#include "Action.h"

// Конструкторы
// По умолчанию
Action::Action(){
    _durationMinute = 0;
}
// Инициализация
Action::Action(string &name, double durationMinute){
    if (durationMinute < 0){
        _durationMinute = 0;
    }
    else {
        _durationMinute = durationMinute;
    }
}
// Копирование
Action::Action(Action const &action){
    _durationMinute = action._durationMinute;
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