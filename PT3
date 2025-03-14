//(Problem 1)
#include <iostream> 
#include <string>

using namespace std;

int main() { 

    char sentence[100], wordToFind[20], replacement[20]; 

    cout << "Enter a sentence: "; 
    cin.getline(sentence, 100); 

    cout << "Enter the word to find: "; 
    cin >> wordToFind; 

    cout << "Enter the replacement word: "; 
    cin >> replacement; 

    char* pos = strstr(sentence, wordToFind); 

    if (pos != nullptr) { 
        char temp[100]; 
        strncpy(temp, sentence, pos - sentence); 
        temp[pos - sentence] = '\0'; 
        strcat(temp, replacement); 
        strcat(temp, pos + strlen(wordToFind)); 
        strcpy(sentence, temp); 

        cout << "Modified sentence: " << sentence << endl; 
    } else { 
        cout << "Word not found in the sentence." << endl; 
    } 

    return 0; 
}

//(Problem 2)
#include <iostream> 
#include <cctype> 

using namespace std; 

int main() { 
    char letter; 

    cout << "Enter a character: "; 
    cin >> letter; 

    if (isalpha(letter)) { 
        if (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' || tolower(letter) == 'o' || tolower(letter) == 'u') { 
            cout << "'" << letter << "' is a vowel." << endl; 
        } else { 
            cout << "'" << letter << "' is a consonant." << endl; 
        } 

        if (isupper(letter)) { 
            cout << "'" << letter << "' is in uppercase." << endl; 
        } else { 
            cout << "'" << letter << "' is in lowercase." << endl; 
        } 
    } else { 
        cout << "'" << letter << "' is not a letter." << endl; 
    } 

     return 0; 
}

//(Problem 3)
#include <iostream> 
#include <cctype> 

using namespace std; 

int main() { 

    string inputString;  

    cout << "Enter an alphanumeric string: "; 
    cin >> inputString; 
  

    for (char &character : inputString) { 
        if (isdigit(character)) { 
            character = '*'; 
        } else if (isalpha(character)) { 
            character = isupper(character) ? tolower(character) : toupper(character); 
        } 
    } 

    cout << "Modified string: " << inputString << endl;  

    return 0; 
}
