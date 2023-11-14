#include "Ingredient.h"
#include "queue"

class Recipe {
public:
    // Конструктор
    Recipe() = default;
    Recipe(const Ingredient * ingredient);
    Recipe(const Recipe& recipe) = default;

    // Добавление шага
    void add(const Step * step);
    // Итерация и удаление
    void nextStep();
    void popFirstStep();

    // Получение текущего шага
    Step * getStep() const;

    // Проверка на пустой рецепт
    bool isEmpty() const;
    // Проверка на корректность рецепта
    bool hasMistakes() const;

    // Консольная распечатка
    void showStep() const;
    void showRecipe() const;

private:
    queue<Step*> recipe;
};
