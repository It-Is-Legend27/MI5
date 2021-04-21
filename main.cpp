#include <iostream>
#include <string>

using namespace std;

void printHeader();
string promptUser();
char promptChoice();
bool isPalindrome(string s);
string replace_all(string text, string from, string to);
string formatString(string s);
bool isLetter(char c);
string changeToLower(string s);

int main()
{
    string text;
    char choice = 'y';

    /* printHeader();

    while (choice != 'n')
    {
        cout << "Enter a palindrome:\n>";
        cin >> text;

        if (isPalindrome(text))
        {
            cout << text << " is a palindrome.\n";
        }
        else
        {
            cout << text << "is not a palindrome.\n";
        }
        choice = promptChoice();
    } */

    cout << "Enter a string:\n> ";
    getline(cin, text);

    text = formatString(text);
    cout << '\n' << text << endl;

    text = changeToLower(text);
    cout << '\n' << text << endl;
    return 0;
}

void printHeader()
{
    cout << "Palindrome Program\n\n\n";
}
string promptUser()
{
    string text;
    cout << "Please enter a palindrone:\n> ";
    getline(cin, text);

    if(text == "")
    {
        promptUser();
    }
    

    return text;
}
char promptChoice()
{
    char choice;
    cout << "\nWould you like to continue [y / n]:\n> ";
    cin >> choice;
    cin.ignore();
    return choice;
}
bool isPalindrome(string s)
{
    if(s.length() < 2)
    {
        return true;
    }
    else if(s[0] == s[s.size()-1])
    {
        isPalindrome(s.substr(1,s.size()-2));
    }
    else
    {
        return false;
    }
}
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
string formatString(string s)
{
    s = replace_all(s, " ", "");
    s = changeToLower(s);

}
bool isLetter(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
string changeToLower(string s)
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