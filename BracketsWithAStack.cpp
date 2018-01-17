// Amber Mickler
// brackets.cpp
// COP4530 Recitation Exercise

#include <stack>
#include <iostream>
#include <string>

using namespace std;

bool match(char open, char close) {
    if (open == '{' && close == '}')
    return true;
    else if (open == '[' && close == ']')
    return true;
    else if (open == '(' && close == ')')
    return true;
    else
    return false;
}

int main() {

    stack<char> brackets;
    string line;

    while (getline(cin,line)) {
        // look for bracket
        for (int i=0; i<line.length(); i++) {
            if (line[i] == '{' || line[i] == '[' || line[i] == '(') {
                // add to Stack
                brackets.push(line[i]);
            }
            // look for matching bracket
            else if (line[i] == '}' || line[i] == ']' || line[i] == ')') {
                // if it matches, pop from Stack
                if (match(brackets.top(), line[i])) {
                    brackets.pop();
                }
                // else push onto stack & look for bracket
                else {
                    brackets.push(line[i]);
                }
            }
        }
    }

    if (brackets.empty())
        cout << "Success! All brackets match up." << endl;
    else
        cout << "Woops! You have some mismatched brackets to fix." << endl;

}
