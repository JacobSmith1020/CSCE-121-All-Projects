#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "mapfunctions.h"
using namespace std;

// Find the maximim and minimum elements of a given two dimensional array of known size
void findMaxMin(const int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, int& max, int& min) {
    max = elevations[0][0];
    min = elevations[0][0];
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(elevations[i][j] > max) {
                max = elevations[i][j];
            }
            else if(elevations[i][j] < min) {
                min = elevations[i][j];
            }
        }
    }
}

// Load elevation data into a two dimensional array based on the number of rows and columns in the data
void loadData(int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, istream& inData) {
    int size = 0;
    int num = 0;
    // Load elevation array
    for(int rowOn = 0; rowOn < rows; ++rowOn) {
        for(int columnOn = 0; columnOn < cols; ++columnOn) {
            inData >> num;
            // Handles non integer values present in elevation data file and when there 
            // is an inconsistency between the number of rows and columns and the number of data points in the file
            if(inData.fail()) {
                cout << "Error: Read a non-integer value." << endl;
                exit(1);
            }
            else if(inData.bad()) {
                cout << "Error: Problem reading the file." << endl;
                exit(1);
            }
            else {
                elevations[rowOn][columnOn] = num;
                ++size;
            }
            if(inData.eof()) {
                if(size < (rows * cols)) {
                    cout << "Error: End of file reached prior to getting all the required data." << endl;
                    exit(1);
                }
                else if(size > (rows * cols)) {
                    cout << "Error: Too many data points." << endl;
                    exit(1);
                }
            }
        }
    }
    inData >> num;
    if(inData.eof()) {
        if(size < (rows * cols)) {
            cout << "Error: End of file reached prior to getting all the required data." << endl;
            exit(1);
        }
        else if(size > (rows * cols)) {
            cout << "Error: Too many data points." << endl;
            exit(1);
        }
    }
}

int scaleValue(int value, int max, int min) {
    double shadeOfGrey = ((double(value) - double(min)) / (double(max) - double(min))) * 255.0;
    int scale = round(shadeOfGrey);
    return scale;
}

void loadGreyscale(Pixel image[MAX_ROWS][MAX_COLS], const int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, int max, int min) {
    int shadeOfGrey = 0;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            shadeOfGrey = scaleValue(elevations[i][j], max, min);
            image[i][j].red = shadeOfGrey;
            image[i][j].green = shadeOfGrey;
            image[i][j].blue = shadeOfGrey;
        }
    }
}

void outputImage(const Pixel image[MAX_ROWS][MAX_COLS], int rows, int cols, ostream& outData) {
    int rowsOn = 0;
    outData << "P3" << endl << cols << " " << rows << endl << 255 << endl;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(i > rowsOn) {
                outData << endl;
                ++rowsOn;
            }
            outData << image[i][j].red << " " << image[i][j].green << " " << image[i][j].blue << " ";
        }
    }
}

int colorPath(const int elevations[MAX_ROWS][MAX_COLS], Pixel image[MAX_ROWS][MAX_COLS], int rows, int cols, Pixel color, int start_row) {
    int elevationSum = 0;
    int elevationDifference1 = 0;
    int elevationDifference2 = 0;
    int elevationDifference3 = 0;
    image[start_row][0].red = color.red;
    image[start_row][0].green = color.green;
    image[start_row][0].blue = color.blue;
    for(int j = 0; j < cols; ++j) {
        if((start_row == 0) && (j != cols-1)) {
            elevationDifference2 = abs(elevations[start_row][j+1] - elevations[start_row][j]);
            elevationDifference3 = abs(elevations[start_row+1][j+1] - elevations[start_row][j]);
            if(elevationDifference2 == elevationDifference3) {
                elevationSum += elevationDifference2;
                image[start_row][j+1].red = color.red;
                image[start_row][j+1].green = color.green;
                image[start_row][j+1].blue = color.blue;
            }
            else if(elevationDifference2 < elevationDifference3) {
                elevationSum += elevationDifference2;
                image[start_row][j+1].red = color.red;
                image[start_row][j+1].green = color.green;
                image[start_row][j+1].blue = color.blue;
            }
            else {
                elevationSum += elevationDifference3;
                image[start_row+1][j+1].red = color.red;
                image[start_row+1][j+1].green = color.green;
                image[start_row+1][j+1].blue = color.blue;
                start_row += 1;
            }
        }
        else if((start_row == (rows-1)) && (j != cols-1)) {
            elevationDifference1 = abs(elevations[start_row-1][j+1] - elevations[start_row][j]);
            elevationDifference2 = abs(elevations[start_row][j+1] - elevations[start_row][j]);
            if(elevationDifference1 == elevationDifference2) {
                elevationSum += elevationDifference2;
                image[start_row][j+1].red = color.red;
                image[start_row][j+1].green = color.green;
                image[start_row][j+1].blue = color.blue;
            }
            else if(elevationDifference1 < elevationDifference2) {
                elevationSum += elevationDifference1;
                image[start_row-1][j+1].red = color.red;
                image[start_row-1][j+1].green = color.green;
                image[start_row-1][j+1].blue = color.blue;
                start_row -= 1;
            }
            else {
                elevationSum += elevationDifference2;
                image[start_row][j+1].red = color.red;
                image[start_row][j+1].green = color.green;
                image[start_row][j+1].blue = color.blue;
            }
        }
        else if(j != cols-1) {
            elevationDifference1 = abs(elevations[start_row-1][j+1] - elevations[start_row][j]);
            elevationDifference2 = abs(elevations[start_row][j+1] - elevations[start_row][j]);
            elevationDifference3 = abs(elevations[start_row+1][j+1] - elevations[start_row][j]);
            if((elevationDifference1 == elevationDifference2) && (elevationDifference1 == elevationDifference3)) {
                elevationSum += elevationDifference2;
                image[start_row][j+1].red = color.red;
                image[start_row][j+1].green = color.green;
                image[start_row][j+1].blue = color.blue;
            }
            else if((elevationDifference1 == elevationDifference2) && (elevationDifference1 < elevationDifference3)) {
                elevationSum += elevationDifference2;
                image[start_row][j+1].red = color.red;
                image[start_row][j+1].green = color.green;
                image[start_row][j+1].blue = color.blue;
            }
            else if((elevationDifference2 == elevationDifference3) && (elevationDifference2 < elevationDifference1)) {
                elevationSum += elevationDifference2;
                image[start_row][j+1].red = color.red;
                image[start_row][j+1].green = color.green;
                image[start_row][j+1].blue = color.blue;
            }
            else if((elevationDifference1 == elevationDifference3) && (elevationDifference1 < elevationDifference2)) {
                elevationSum += elevationDifference3;
                image[start_row+1][j+1].red = color.red;
                image[start_row+1][j+1].green = color.green;
                image[start_row+1][j+1].blue = color.blue;
                start_row += 1;
            }
            else if((elevationDifference1 < elevationDifference2) && (elevationDifference1 < elevationDifference3)) {
                elevationSum += elevationDifference1;
                image[start_row-1][j+1].red = color.red;
                image[start_row-1][j+1].green = color.green;
                image[start_row-1][j+1].blue = color.blue;
                start_row -= 1;
            }
            else if((elevationDifference2 <= elevationDifference1) && (elevationDifference2 <= elevationDifference3)) {
                elevationSum += elevationDifference2;
                image[start_row][j+1].red = color.red;
                image[start_row][j+1].green = color.green;
                image[start_row][j+1].blue = color.blue;
            }
            else {
                elevationSum += elevationDifference3;
                image[start_row+1][j+1].red = color.red;
                image[start_row+1][j+1].green = color.green;
                image[start_row+1][j+1].blue = color.blue;
                start_row += 1;
            }
        }
    }
    return elevationSum;
}