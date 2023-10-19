#include "iostream"
#include "cassert"
#include "Recipe.h"

using namespace std;

int main() {
    // Тест класса Ingredient
    string testIngredientName = "carrot";
    string testMeasureUnit = "kg";
    double testAmount = 1.5;
    string testIngredientName2 = "milk";

    // Проверка на значения по умолчанию
    Ingredient defaultIngredient = Ingredient();
    assert(defaultIngredient.getName().empty());
    assert(defaultIngredient.getMeasureUnit().empty());
    assert(defaultIngredient.getAmount() == 0);

    // Проверка конструктора инициализации
    Ingredient initedIngredient = Ingredient(testIngredientName, testMeasureUnit, testAmount);
    assert(initedIngredient.getName() == testIngredientName);
    assert(initedIngredient.getMeasureUnit() == testMeasureUnit);
    assert(initedIngredient.getAmount() == testAmount);

    // Проверка конструктора копирования
    Ingredient copiedIngredient = Ingredient(initedIngredient);
    assert(copiedIngredient.getName() == testIngredientName);
    assert(copiedIngredient.getMeasureUnit() == testMeasureUnit);
    assert(copiedIngredient.getAmount() == testAmount);

    // Проверка модификаторов и селекторов
    defaultIngredient.setName(testIngredientName);
    defaultIngredient.setMeasureUnit(testMeasureUnit);
    defaultIngredient.setAmount(testAmount);

    assert(defaultIngredient.getName() == testIngredientName);
    assert(defaultIngredient.getMeasureUnit() == testMeasureUnit);
    assert(defaultIngredient.getAmount() == testAmount);

    // Тест класса Action
    string testActionName = "cut";
    double testDurationMinute = 14.5;

    // Конструкторы
    // По умолчанию
    Action defaultAction = Action();
    assert(defaultAction.getName().empty());
    assert(defaultAction.getDurationMinute() == 0);

    // Инициализации
    Action initedAction = Action(testActionName, testDurationMinute);
    assert(initedAction.getName() == testActionName);
    assert(initedAction.getDurationMinute() == testDurationMinute);

    // Копирования
    Action copiedAction = Action(initedAction);
    assert(copiedAction.getName() == testActionName);
    assert(copiedAction.getDurationMinute() == testDurationMinute);

    // Геттеры и сеттеры
    defaultAction.setName(testActionName);
    defaultAction.setDurationMinute(testDurationMinute);

    assert(defaultAction.getName() == testActionName);
    assert(defaultAction.getDurationMinute() == testDurationMinute);

    cout << "All tests passed" << endl;

//    Recipe recipe = Recipe(defaultIngredient);
//    recipe.add(copiedIngredient);
//    recipe.add(copiedAction);
//    recipe.showRecipe();
//    cout << "======" << endl;
//    copiedAction.setName(testIngredientName2);
//    cout << copiedAction.getName() << endl;
//    recipe.showRecipe();
//    cout << "======" << endl;
//    Recipe recipe2 = Recipe(recipe);


    return 0;
}
