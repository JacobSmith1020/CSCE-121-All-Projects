#include <iostream>
using namespace std;


unsigned long long int sequence(int n) {
    // Ln = Ln-1 + Ln-2
    if (n < 2) {
        return 2 - n;
    }
    else {
        return sequence(n - 1) + sequence(n - 2);
    }
}


int main() {
    int num = 0;
    cin >> num;
    cout << "n: " << sequence(num) << endl;
    return 0;
}