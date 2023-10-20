#include "Ingredient.h"

class Recipe {
public:
    Recipe();
    Recipe(const Step *step);
    // Recipe(Recipe &recipe);

    void add(Step *step);
    void next();
    void pop();

    bool stepIsIngredient();
    bool stepIsAction();
    bool isEmpty();

    Step * getStep();

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
