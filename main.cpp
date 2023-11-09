#include "iostream"
#include "cassert"
#include "Recipe.h"

using namespace std;

int main() {
    // Тест класса Step
    string testStepName = "step";

    // Проверка на значения по умолчанию
    Step defaultStep = Step();
    assert(defaultStep.getName().empty());

    // Проверка конструктора инициализации
    Step initedStep = Step(testStepName);
    assert(initedStep.getName() == testStepName);

    // Проверка конструктора копирования
    Step copiedStep = Step(initedStep);
    assert(copiedStep.getName() == testStepName);

    // Проверка модификаторов и селекторов
    defaultStep.setName(testStepName);
    assert(defaultStep.getName() == testStepName);

    cout << "Tests for class Step are passed" << endl;

    // Тест класса Ingredient
    string testIngredientName = "carrot";
    string testMeasureUnit = "kg";
    double testAmount = 1.5;

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

    cout << "Tests for class Ingredient are passed" << endl;

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

    cout << "Tests for class Action are passed" << endl;

    // Тест класса Recipe
    // Значения по умолчанию
    Recipe defaultRecipe = Recipe();
    assert(defaultRecipe.isEmpty() == true);

    // Проверка конструктора инициализации
    Recipe initedRecipe1 = Recipe(&initedStep);
    assert(initedRecipe1.getStep()->getName() == testStepName);

    Recipe initedRecipe2 = Recipe(&initedIngredient);
    assert(((Ingredient *)initedRecipe2.getStep())->getName() == testIngredientName);
    assert(((Ingredient *)initedRecipe2.getStep())->getAmount() == testAmount);
    assert(((Ingredient *)initedRecipe2.getStep())->getMeasureUnit() == testMeasureUnit);

    Recipe initedRecipe3 = Recipe(&initedAction);
    assert(((Action *)initedRecipe3.getStep())->getName() == testActionName);
    assert(((Action *)initedRecipe3.getStep())->getDurationMinute() == testDurationMinute);

    // Проверка конструктора копирования
    Recipe copiedRecipe1 = Recipe(initedRecipe1);
    assert(copiedRecipe1.getStep()->getName() == testStepName);

    Recipe copiedRecipe2 = Recipe(initedRecipe2);
    assert(((Ingredient *)copiedRecipe2.getStep())->getName() == testIngredientName);
    assert(((Ingredient *)copiedRecipe2.getStep())->getAmount() == testAmount);
    assert(((Ingredient *)copiedRecipe2.getStep())->getMeasureUnit() == testMeasureUnit);

    Recipe copiedRecipe3 = Recipe(initedRecipe3);
    assert(((Action *)copiedRecipe3.getStep())->getName() == testActionName);
    assert(((Action *)copiedRecipe3.getStep())->getDurationMinute() == testDurationMinute);

    // Проверка add, get, next, pop
    initedRecipe2.add(&initedAction);
    assert(((Ingredient *)initedRecipe2.getStep())->getName() == testIngredientName);
    assert(((Ingredient *)initedRecipe2.getStep())->getAmount() == testAmount);
    assert(((Ingredient *)initedRecipe2.getStep())->getMeasureUnit() == testMeasureUnit);
    initedRecipe2.next();
    assert(((Action *)initedRecipe3.getStep())->getName() == testActionName);
    assert(((Action *)initedRecipe3.getStep())->getDurationMinute() == testDurationMinute);
    initedRecipe2.pop();
    assert(initedRecipe2.isEmpty() == true);

    cout << "Tests for class Recipe are passed" << endl;

    // Тестирование виртуальных функций
    assert(initedStep.identify() == step);
    assert(initedIngredient.identify() == ingredient);
    assert(initedAction.identify() == action);

    assert(copiedRecipe2.getStep()->identify() == ingredient);
    assert(copiedRecipe3.getStep()->identify() == action);

    // Проверка межклассового взаимодействия
    Action newAction;
    Step* step1 = & newAction;
    assert(step1->identify() == action);

    Ingredient newIngredient;
    Step* step2 = & newIngredient;
    assert(step2->identify() == ingredient);

    cout << "Tests for virtual functions are passed" << endl;

    return 0;
}
