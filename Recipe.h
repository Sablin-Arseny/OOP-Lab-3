#include "Ingredient.h"
#include "queue"

class Recipe {
public:
    // Конструктор
    Recipe() = default;
    Recipe(const Ingredient * ingredient);
    Recipe(Recipe& recipe) = default;

    // Добавление шага
    void add(const Step * step);
    // Итерация и удаление
    void next();
    void pop();

    // Получение текущего шага
    Step * getStep() const;

    // Проверка на пустой рецепт
    bool isEmpty();
    // Проверка на корректность рецепта
    bool hasMistakes();

    // Консольная распечатка
    void showStep();
    void showRecipe();

private:
    queue<Step*> recipe;
};
