#include "Ingredient.h"

class Recipe {
public:
    // Конструкторы
    Recipe();
    Recipe(const Step *step);
    Recipe(Recipe &recipe) = default;

    // Добавление, итерация, удаление
    void add(const Step *step);
    void next();
    void pop();

    // Проверки
    bool stepIsIngredient() const;
    bool stepIsAction() const;
    bool isEmpty() const;

    // Геттер
    Step * getStep() const;

    // Консольный вывод
    void showStep();
    void showRecipe();

private:
    struct Node {
        Step *_step = nullptr;
        struct Node *_left = nullptr; // лево на действие
        struct Node *_right = nullptr; // право на ингредиент
    } typedef node;

    node *_root;
};
