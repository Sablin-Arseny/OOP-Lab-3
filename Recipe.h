#include "Ingredient.h"

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
        Step _step;
        struct Node *_left = nullptr; // лево на действие
        struct Node *_right = nullptr; // право на ингредиент
    } typedef node;

    node *_root;
};
