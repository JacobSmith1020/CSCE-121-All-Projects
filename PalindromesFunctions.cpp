#include "functionsPalindromes.h"
using namespace std;

void printUsage(string programName) {
    cout << "Usage: " << programName << " [-c]  [-s] string ..." << endl;
    cout << "  -c: turn on case sensitivity" << endl;
    cout << "  -s: turn off ignoring spaces" << endl;
}

bool isPalindromeR(string userText, unsigned int iteration = 0) {
    if (userText[iteration] == userText[userText.length() - iteration - 1]) {
        if (iteration == userText.length()) {
            return true;
        }
        else {
            iteration += 1;
            return isPalindromeR(userText, iteration);
        }
    }
    else {
        return false;
    }
}

bool isPalindrome(string userText, bool caseFlag, bool spaceFlag) {
    if (caseFlag == false) {
        string noCaseUserText = " ";
        for (unsigned int j = 0; j < userText.length(); ++j) {
            noCaseUserText += tolower(userText[j]);
        }
        userText = noCaseUserText;
    }
    if (spaceFlag == true) {
        for (unsigned int i = 0; i < userText.length(); ++i) {
            if (userText[i] == ' ') {
                userText.erase(i, 1);
            }
        }
    }
    return isPalindromeR(userText);
}