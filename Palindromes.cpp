#include "functionsPalindromes.h"
using namespace std;

int main(int argc, char* argv[]) {
    bool caseSensitive = false;
    bool spaceSensitive = true;
    string text = " ";
    string flag = " ";
    // Check if enough arguments are given
    if (argc < 2) {
        printUsage(argv[0]);
        exit(1);
    }
    // Determine flags and where they are placed
    if ('-' == argv[1][0]) {
        flag = argv[1];
        int lengthFlag = flag.length();
        if (lengthFlag < 2) {
            printUsage(argv[0]);
            exit(1);
        }
        text = argv[2];
        if (lengthFlag == 2) {
            if (('c' == argv[1][1]) || ('C' == argv[1][1]) ) {
                caseSensitive = true;
            }
            else if (('s' == argv[1][1]) || ('S' == argv[1][1])) {
                spaceSensitive = false;
            }
        }
        else if (lengthFlag >= 3) {
            if (('c' == argv[1][1]) || ('C' == argv[1][1]) || ('c' == argv[1][2]) || ('C' == argv[1][2])) {
                caseSensitive = true;
            }
            if (('s' == argv[1][1]) || ('S' == argv[1][1]) || ('s' == argv[1][2]) || ('S' == argv[1][2])) {
                spaceSensitive = false;
            } 
        }
        for(int k = 0; k <= argc; ++k) {
            bool PalindromeValue = isPalindrome(argv[k + 2], caseSensitive, spaceSensitive);
            if (PalindromeValue == true) {
                cout << argv[k + 2] << " is a palindrome." << endl;
            }
            else {
                cout << argv[k + 2] << " is not a palindrome." << endl;
            }
        }
    }
    else {
        text = argv[1];
        for(int k = 0; k <= argc; ++k) {
            bool PalindromeValue = isPalindrome(argv[k + 1], caseSensitive, spaceSensitive);
            if (PalindromeValue == true) {
                cout << argv[k + 1] << " is a palindrome." << endl;
            }
            else {
                cout << argv[k + 1] << " is not a palindrome." << endl;
            }
        }   
    }
    return 0;
}