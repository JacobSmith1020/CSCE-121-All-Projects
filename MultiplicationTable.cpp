#include <vector>
#include <iostream>
using namespace std;

int main() {
    int width = 0;
    int height = 0;
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    vector<int> widthTable = vector<int>(width);
    vector<int> heightTable = vector<int>(height);
    for(int a = 0; a < width; ++a) {
        widthTable[a] = a;
    }
    for(int b = 0; b < width; ++b) {
        widthTable[b] = b;
    }
    vector<vector<int>> multTable = vector<vector<int>>(9);
    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            multTable[i][j] = widthTable[i] * heightTable[j];
        }
    } 
}