#include <iostream>
#include <string>

using namespace std;

void printHeader();
string promptString();
char promptChoice();
bool isLetter(char c);
bool isValidString(string s);
bool isPalindrome(string s);
string formatString(string s);
string replace_all(string text, string from, string to);
string setLowerCase(string s);

int main()
{
    string text;
    char choice = 'y';

    // Prints title of program
    printHeader();

    while (choice != 'n' && choice != 'N')
    {
       // Prompts user to enter a palindrome
       text = promptString();
       
       // Formats user's input so it can be checked
       // by bool isPalindrome(string s)
       // Original is unmodified so it can be printed afterward
       string temp = formatString(text);
 
        if(isPalindrome(temp))
        {
            cout << text << " is a palindrome.\n";
        }
        else
        {
            cout << text << " is not a palindrome.\n";
        }
        
        // Prompts user to enter 'y' to continue or 'n' to stop the program
        choice = promptChoice();
    }
    return 0;
}

// Prints header for program
void printHeader()
{
    cout << "Palindrome Program\n\n\n";
}

// Prompts user to enter string and returns it
string promptString()
{
    string text;
    cout << "Please enter a palindrone:\n> ";
    getline(cin, text);

    while(text == "" || !isValidString(text))
    {
        cout << "\nInvalid input.\n";
        cout << "Input must consist of letters or spaces.\n";
        cout << "Please enter a palindrone:\n> ";
        getline(cin, text);
    }

    return text;
}

// Returns true if character is a uppercase letter or lowercase letter
bool isLetter(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Returns true if string only consists of spaces and letters
bool isValidString(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
    
        if(s[i] != ' ')
        {
            if(!isLetter(s[i]))
            {
                return false;
            }
        }
    }
    return true;
}

// Prompts user to enter 'n' or 'y' (allows 'Y' or 'N)
char promptChoice()
{
    char choice;
    cout << "\nWould you like to continue [y / n]:\n> ";
    cin >> choice;
    
    while(choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y')
    {
        cout << "\n Invalid input.\n";
        cout << "\nWould you like to continue [y / n]:\n> ";
        cin >> choice;
    }
    cin.ignore();
    
    return choice;
}

// Checks the first and last characters of the string
// (moving the "ends" of the string up toward the middle) recursively
// to see if the string is a palindrome
bool isPalindrome(string s)
{
    if(s.length() < 2)
    {
        return true;
    }
    else if(s[0] == s[s.size()-1])
    {
        return isPalindrome(s.substr(1,s.size()-2));
    }
    return false;
}

// Formats the string so it can be checked by bool isPalindrome(string s)
// Removes all spaces and changes all letters to lowercase
string formatString(string s)
{
    s = replace_all(s, " ", "");
    s = setLowerCase(s);
    return s;
}

// Checks every character in the string and replaces
// every uppercase letter with a lowercase letter
string setLowerCase(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] < 'a')
        {
            s[i] = tolower(s[i]);
        }
    }
    return s;
}

// Searches for a substring "from" within "text" and replaces all instances
// with "to"
string replace_all(string text, string from, string to)
{
    size_t start_pos = 0;
    // While we can find the substring "from"
    // (start position changes each time we make a replacement)
    while ((start_pos = text.find(from, start_pos)) != string::npos)
    {
        // Make the replacement
        text.replace(start_pos, from.length(), to);
        // Move past the string replacement's length, we don't need to
        // check it
        start_pos += to.length();
    }
    return text;
}