#include "Ingredient.h"
#include "Action.h"

class Recipe {
public:
    Recipe();
    Recipe(const Ingredient &ingredient);
    Recipe(Recipe &recipe);

    void add(const Ingredient &ingredient);
    void add(const Action &action);
    void next();
    void pop();

    bool isIngredient();
    bool isAction();
    bool isEmpty();

    Ingredient getIngredient();
    Action getAction();

    void showStep();
    void showRecipe();

private:
    struct Node {
        Ingredient _ingredient;
        Action _action;
        struct Node *_left = nullptr; // лево на действие
        struct Node *_right = nullptr; // право на ингредиент
        bool _isIngredient; // true - ингредиент, false - действие
    } typedef node;

    node *_root;
};
