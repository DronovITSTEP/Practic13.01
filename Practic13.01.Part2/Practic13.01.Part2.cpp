#include <iostream>

using namespace std;

void hello() {
    cout << "Hello\n";
}
void Goodbye() {
    cout << "Good bye\n";
}

int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mult(int a, int b) {
    return a * b;
}
void operation(int(*op)(int, int), int a, int b) {
    cout << op(a, b) << endl;
}

int IsEven(int x) {
    return x % 2 == 0;
}
int IsPositive(int x) {
    return x > 0;
}
void action(int(*con)(int), int number[], int n) {
    for (int i = 0; i < n; i++) {
        if (con(number[i]) != 0) {
            cout << number[i] << " ";
        }
    }
    cout << endl;
}

void goodmorning() {
    cout << "Good morning!\n";
}
void goodevening() {
    cout << "Good evening!\n";
}
void(*message(int h))() {
    if (h > 12) return goodevening;
    else goodmorning;
}

int(*select())(int, int) {
    int choise;
    int (*action[])(int, int) { add, sub, mult };
    cout << "Enter action (1-2-3-4) -> "; cin >> choise;

    if (choise > 0 && choise < 4) return action[choise - 1];
    else return NULL;
}

int main()
{
    // объявление указателя на функцию
    //тип(*имя_указателя)(параметры);

    /*void (*message) ();
    message = hello;
    message();
    message = Goodbye;
    message();*/

    /*int a = 10;
    int b = 5;

    int (*operation)(int, int);
    operation = add;
    int result = operation(a, b);
    cout << result << endl;
    operation = sub;
    result = operation(a, b);
    cout << result << endl;*/

    // массив указателей на функции
    //тип(*имя_указателя[размер])(параметры);

    /*int a = 10, b = 5;
    int (*operation[3])(int, int) = { add, sub, mult };
    int length = sizeof(operation) / sizeof(operation[0]);

    for (int i = 0; i < length; i++) {
        cout << operation[i](a, b) << " ";
    }
    */

    /*int a = 10, b = 5;
    operation(add, a, b);
    operation(mult, a, b);*/

    /*int num[] = {5,-7,6,9,-1,6,7,7,-5,-9,3};

    action(IsEven, num, 11);
    action(IsPositive, num, 11);*/

    /*void(*action)();
    action = message(15);
    action();*/

    int x = 8, y = 5;
    cout << "1: Add\n"
        << "2: Sub\n"
        << "3: Mult\n"
        << "4: Exit\n";
    int(*action)(int, int);
    int result;

    while (1)
    {
        action = select();
        if (action == NULL) break;
        result = action(x, y);
        cout << result << endl;
    }
    cout << "End!";

}
