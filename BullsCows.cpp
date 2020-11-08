#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;


int digitInput(int &codeReference, int &cheatActivated) {
    // Take input from the user on how many digits will be in the code and if the digits is zero activate the cheat path
    int digitNum = 1;
    while(true) {
        cout << "Enter number of digits in code (3, 4 or 5): ";
        cin >> digitNum;
        if ((digitNum == 0) || (digitNum == 3) || (digitNum == 4) || (digitNum == 5)) {
            break;
        }
        else {
            cout << "The current supported digit lengths are 0, 3, 4 and 5. Please pick a supported digit length." << endl;
        }
    }
    if(digitNum == 0) {
        cout << "Enter code: ";
        cin >> codeReference;
        cout << "Enter number of digits in code: ";
        cin >> digitNum;
        cheatActivated = 1;
    }
    return digitNum;
}


void randomCode(int digits, int cheatValue, int cheatCode, int &digit1, int &digit2, int &digit3, int &digit4, int &digit5) {
    // Make a code of unique integers of specified length from the user
    // Cheat path
    if(cheatValue == 1) {
        // Cheat code of length 3
        if(digits == 3) {
            digit1 = (cheatCode / 100);
            digit2 = (cheatCode / 10) % 10;
            digit3 = (cheatCode / 1) % 10;
        }
        // Cheat code of length 4
        else if(digits == 4) {
            digit1 = cheatCode / 1000;
            digit2 = (cheatCode / 100) % 10;
            digit3 = (cheatCode / 10) % 10;
            digit4 = (cheatCode / 1) % 10;
        }
        // Cheat code of length 5
        else if(digits == 5) {
            digit1 = cheatCode / 10000;
            digit2 = (cheatCode / 1000) % 10;
            digit3 = (cheatCode / 100) % 10;
            digit4 = (cheatCode / 10) % 10;
            digit5 = (cheatCode / 1) % 10;
        }
    }
    // Random code
    // Three digits
    else if(cheatValue == 0) {
        if(digits == 3) {
            digit1 = rand() % 10;
            do {
                digit2 = rand() % 10;
            } while(digit2 == digit1);
            do {
                digit3 = rand() % 10;
            } while((digit3 == digit1) || (digit3 == digit2));
        }
        // Four digits
        else if(digits == 4) {
            digit1 = rand() % 10;
            do {
                digit2 = rand() % 10;
            } while(digit2 == digit1);
            do {
                digit3 = rand() % 10;
            } while((digit3 == digit1) || (digit3 == digit2));
            do {
                digit4 = rand() % 10;
            } while((digit4 == digit1) || (digit4 == digit2) || (digit4 == digit3));
        }
        // Five digits
        else if(digits == 5) {
            digit1 = rand() % 10;
            do {
                digit2 = rand() % 10;
            } while(digit2 == digit1);
            do {
                digit3 = rand() % 10;
            } while((digit3 == digit1) || (digit3 == digit2));
            do {
                digit4 = rand() % 10;
            } while((digit4 == digit1) || (digit4 == digit2) || (digit4 == digit3));
            do {
                digit5 = rand() % 10;
            } while((digit5 == digit1) || (digit5 == digit2) || (digit5 == digit3) || (digit5 == digit4));
        }
    }  
}


int numberArray(int &d1, int &d2, int &d3, int &d4, int &d5) {
    // Place the random digits generated or the code input by the user into an array
    int code = 0;
    int cheat = 0;
    int digitNumber = digitInput(code, cheat);
    randomCode(digitNumber, cheat, code, d1, d2, d3, d4, d5);
    int codeArray[5] = {d1, d2, d3, d4, d5};
    // Output number to guess
    if(digitNumber == 3) {
        for(int i = 0; i < 3; ++i) {
            if(i == 0) {
                cout << "Number to guess: " << codeArray[i] << "-";
            }
            else if(i == 2) {
                cout << codeArray[i] << endl;
            } 
            else {
                cout << codeArray[i] << "-";
            }
        }
    }
    else if(digitNumber == 4) {
        for(int i = 0; i < 4; ++i) {
            if(i == 0) {
                cout << "Number to guess: " << codeArray[i] << "-";
            }
            else if(i == 3) {
                cout << codeArray[i] << endl;
            } 
            else {
                cout << codeArray[i] << "-";
            }
        }
    }
    else if(digitNumber == 5) {
        for(int i = 0; i < 5; ++i) {
            if(i == 0) {
                cout << "Number to guess: " << codeArray[i] << "-";
            }
            else if(i == 4) {
                cout << codeArray[i] << endl;
            } 
            else {
                cout << codeArray[i] << "-";
            }
        }
    }
    return digitNumber;
}


void guessNum(int digits, int c1, int c2, int c3, int c4, int c5) {
    int codeArray[5] = {c1, c2, c3, c4, c5};
    int userGuess = 0;
    int bulls = 0;
    int cows = 0;
    int repeat = 1;
    int guessArray[5] = {0, 0, 0, 0, 0};
    do {
        // repeat user guesses until they win the game
        while(repeat == 1) {
            cout << "Enter Guess: ";
            cin >> userGuess;
            if(userGuess < 0) {
                cout << "You must guess a positive integer" << endl;
                continue;
            }
            //3 digit guess
            if(digits == 3) {
                int g1 = (userGuess / 100);
                int g2 = (userGuess / 10) % 10;
                int g3 = (userGuess / 1) % 10;
                guessArray[0] = g1;
                guessArray[1] = g2;
                guessArray[2] = g3;
                for(int i = 0; i < 2; ++i) {
                    if(guessArray[0] > 9) {
                        cout << "You can only enter " << digits << " digits." << endl;
                        repeat = 1;
                        break;
                    }
                    else if((i == 0) && ((guessArray[i] == guessArray[i + 1]) || (guessArray[i] == guessArray[i + 2]))) {
                        cout << "Each number must be different." << endl;
                        repeat = 1;  
                        break;  
                    }
                    else if((i == 1) && ((guessArray[i] == guessArray[i + 1]))) {
                        cout << "Each number must be different." << endl;
                        repeat = 1;
                        break;
                    }
                    else {
                        repeat = 0;
                    }
                }
            }
            //4 digit guess
            else if(digits == 4) {
                int g1 = userGuess / 1000;
                int g2 = (userGuess / 100) % 10;
                int g3 = (userGuess / 10) % 10;
                int g4 = (userGuess / 1) % 10;
                guessArray[0] = g1;
                guessArray[1] = g2;
                guessArray[2] = g3;
                guessArray[3] = g4;
                for(int i = 0; i < 3; ++i) {
                    if(guessArray[0] > 9) {
                        cout << "You can only enter " << digits << " digits." << endl;
                        repeat = 1;
                        break;
                    }
                    else if((i == 0) && ((guessArray[i] == guessArray[i + 1]) || (guessArray[i] == guessArray[i + 2]) || (guessArray[i] == guessArray[i + 3]))) {
                        cout << "Each number must be different." << endl;
                        repeat = 1;  
                        break;  
                    }
                    else if((i == 1) && ((guessArray[i] == guessArray[i + 1]) || (guessArray[i] == guessArray[i + 2]))) {
                        cout << "Each number must be different." << endl;
                        repeat = 1;
                        break;
                    }
                    else if((i == 2) && ((guessArray[i] == guessArray[i + 1]))) {
                        cout << "Each number must be different." << endl;
                        repeat = 1;
                        break;
                    }
                    else {
                        repeat = 0;
                    }
                }
            }
            //5 digit guess
            else if(digits == 5) {
                int g1 = userGuess / 10000;
                int g2 = (userGuess / 1000) % 10;
                int g3 = (userGuess / 100) % 10;
                int g4 = (userGuess / 10) % 10;
                int g5 = (userGuess / 1) % 10;
                guessArray[0] = g1;
                guessArray[1] = g2;
                guessArray[2] = g3;
                guessArray[3] = g4;
                guessArray[4] = g5;
                for(int i = 0; i < 4; ++i) {
                    if(guessArray[0] > 9) {
                        cout << "You can only enter " << digits << " digits." << endl;
                        repeat = 1;
                        break;
                    }
                    else if((i == 0) && ((guessArray[i] == guessArray[i + 1]) || (guessArray[i] == guessArray[i + 2]) || (guessArray[i] == guessArray[i + 3]) || (guessArray[i] == guessArray[i + 4]))) {
                        cout << "Each number must be different." << endl;
                        repeat = 1; 
                        break;   
                    }
                    else if((i == 1) && ((guessArray[i] == guessArray[i + 1]) || (guessArray[i] == guessArray[i + 2]) || (guessArray[i] == guessArray[i + 3]))) {
                        cout << "Each number must be different." << endl;
                        repeat = 1;
                        break;
                    }
                    else if((i == 2) && ((guessArray[i] == guessArray[i + 1]) || (guessArray[i] == guessArray[i + 2]))) {
                        cout << "Each number must be different." << endl;
                        repeat = 1;
                        break;
                    }
                    else if((i == 3) && ((guessArray[i] == guessArray[i + 1]))) {
                        cout << "Each number must be different." << endl;
                        repeat = 1;
                        break;
                    }
                    else {
                        repeat = 0;
                    }
                }
            }
        }
        // bulls and cows
        for(int j = 0; j < digits; ++j) {
            for(int k = 0; k < digits; ++k) {
                if(guessArray[j] == codeArray[k]) {
                    if(j == k){
                        bulls += 1;
                    }
                    else {
                        cows += 1;
                    }
                }
            }
        }
        if(bulls != digits) {
            repeat = 1;
            cout << bulls << " bulls" << endl;
            cout << cows << " cows" << endl;
            bulls = 0;
            cows = 0;
        }
        else {
            repeat = 0;
            cout << bulls << " bulls... ";
        }
    } while(bulls != digits);
    if(bulls == digits) {
        for(int g = 0; g < digits; ++g) {
            if(g == digits - 1) {
                cout << guessArray[g];
            }
            else {
                cout << guessArray[g] << "-";
            }
        }
        cout << " is correct!" << endl;
    }
}


int main() {
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
    (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000); 
    // needed to autograde some test cases in Mimir
    int code1 = 0;
    int code2 = 0;
    int code3 = 0;
    int code4 = 0;
    int code5 = 0;
    int digitNum = numberArray(code1, code2, code3, code4, code5);
    guessNum(digitNum, code1, code2, code3, code4, code5);
    return 0;
}