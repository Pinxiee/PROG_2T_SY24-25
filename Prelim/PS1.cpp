#include <iostream>
#include <string>

using namespace std;

int main (){  
    int jeepney_number;
    char jeepney_letter;
    string location;

    cout << "Enter the jeepney's number: ";
    cin >> jeepney_number;

    cout << "Enter the jeepney's letter: ";
    cin >> jeepney_letter;

    if ((jeepney_number == 12) && (jeepney_letter == 'A')){
        location = "Carbon";
    } else if ((jeepney_number == 12) && (jeepney_letter == 'C')){
        location = "Panganiban";
    } else if ((jeepney_number == 12) && (jeepney_letter == 'F')){
        location = "Taboan";
    } else if ((jeepney_number == 12) && (jeepney_letter == 'G' || jeepney_letter == 'I')){
        location = "Malobo";
    } else if ((jeepney_number == 12) && (jeepney_letter == 'L')){
        location = "Labangon";
    } else if ((jeepney_number == 13) && (jeepney_letter == 'C')){
        location = "Talamban";
    } else if ((jeepney_number == 14) && (jeepney_letter == 'D')){
        location = "Capitol";
    } else {
        location = "Jeepney number or letter is invalid";
    }

    cout << "Usual location = " << location << endl;
}