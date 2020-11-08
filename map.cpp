#include <iostream>
#include <fstream>
#include <string>
#include "mapfunctions.h"
using namespace std;

// Normally you should not use global variables. However, the stack is
//   limited in size and will not allow arrays of this size. We'll learn
//   later how to put these arrays on the heap instead. Regardless, for now
//   we'll use these and treat them as if they were declared in main. So
//   when used in functions, we'll pass them as we would any other array.
static int elevations[MAX_ROWS][MAX_COLS];
static Pixel image[MAX_ROWS][MAX_COLS];

int main() {
    int rows = 0;
    int columns = 0;
    int maximum = 0;
    int minimum = 0;
    int start_row = 0;
    int minDistance = 0;
    int minRow = 0;
    string filename;
    cin >> rows;
    cin >> columns;
    cin >> filename;
    if((rows <= 0) || (columns <= 0)) {
        cout << "Error: Problem reading in rows and columns." << endl;
        return 1;
    }
    ifstream inData;
    ofstream outData;
    // open elevation data file
    inData.open(filename);
    // check if elevation file is open
    if(!inData.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return 1;
    }
    if(inData.fail()) {
        cout << "Error: Problem reading the file." << endl;
        return 1;
    }
    // load elevation array
    loadData(elevations, rows, columns, inData);
    inData.close();
    string ppmFile = filename + ".ppm";
    // open output ppm file
    outData.open(ppmFile);
    // find max and min elements in elevation array
    findMaxMin(elevations, rows, columns, maximum, minimum);
    // load greyscale values for all values in elevation array
    loadGreyscale(image, elevations, rows, columns, maximum, minimum);
    // color paths of least elevation change in red
    Pixel color;
    color.red = 252;
    color.green = 25;
    color.blue = 63;
    for(int i = 0; i < rows; ++i) {
        int distance = colorPath(elevations, image, rows, columns, color, i);
        if(i == 0) {
            minDistance = distance;
            minRow = 0;
        }
        else {
            if(distance < minDistance) {
                minDistance = distance;
                minRow = i;
            }
        }
    }
    // color path of least elevation change in green
    color.red = 31;
    color.green = 253;
    color.blue = 13;
    colorPath(elevations, image, rows, columns, color, minRow);
    // write to ppm file
    outputImage(image, rows, columns, outData);
    outData.close();
    return 0;
}