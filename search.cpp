// Example program
#include <iostream>
#include <limits>
using namespace std;

int main()
{

    char searchTerms[256];
    double maxPrice = 50;

    
    cout << "Enter Maximum Price: ";
    cin >> maxPrice;
    // cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    

    cout << "Enter Search Terms: ";

    // cin >> searchTerms;

    cin.getline(searchTerms, 256);

    cout << endl << "Searching for: " << searchTerms << endl;
    cout << "With a maximum price of: " << maxPrice << endl;

}