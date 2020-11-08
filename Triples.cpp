#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int num5 = 0;
    cin >> num1;
    cin >> num2;
    cin >> num3;
    cin >> num4;
    cin >> num5;
    int tripleArray[5] = {num1, num2, num3, num4, num5};
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            for(int k = 0; k < 5; ++k) {
                if(((pow(tripleArray[i], 2)) + (pow(tripleArray[j],2))) == pow(tripleArray[k], 2)) {
                    cout << tripleArray[i] << " " << tripleArray[j] << " " << tripleArray[k] << " are triples" << endl;
                }
            }
        }
    }
    return 0;
}