#include <iostream>
#include <vector>
#include "Function.h" 

using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF-8");
    vector<Function*> myFunctions;

    // Проверка 
    myFunctions.push_back(new Hiperbola(1.0, 0.0));       // f(x) = 1/x
    myFunctions.push_back(new Parabola(1.0, 0.0, 0.0));    // f(x) = x^2
    myFunctions.push_back(new Exponenta(1.0, 0.0));      // f(x) = 1 * e^0 = 1 (всегда единица)
    myFunctions.push_back(new Polinom({ 0, 1 }));        // f(x) = 0 + 1*x (просто прямая y = x)

    for (Function* f : myFunctions) {
        cout << "--- " << f->getName() << " ---" << endl;

        // точка х = 2
        f->printResult(2.0);

        // Проверяем интервал [1, 4]
        f->findExtremes(1.0, 4.0);

        cout << "-----------------------------------" << endl;
    }

    return 0;
}