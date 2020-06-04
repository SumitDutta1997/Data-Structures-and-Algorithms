// Balanced parenthesis

#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<string.h>
using namespace std;

int balancedParenthesis(string expr)
{
    stack<char>s;
    char x;
    for(int i=0 ; i<expr.length() ; i++)
    {
        if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            s.push(expr[i]);
            continue;
        }

        if(s.empty())
            return 0;

        if(expr[i] == ')')
        {
            x = s.top();
            if(x == '[' || x == '{')
                return 0;
            else
                s.pop();
        }
        if(expr[i] == ']')
        {
            x = s.top();
            if(x == '(' || x == '{')
                return 0;
            else
                s.pop();
        }
        if(expr[i] == '}')
        {
            x = s.top();
            if(x == '[' || x == '(')
                return 0;
            else
                s.pop();
        }
    }
    return (s.empty());
}

int main()
{
    char expr[50];
    cout << "Enter a string : ";
    gets(expr);
    balancedParenthesis(expr) ? cout << "Balanced" : cout << "Not Balanced";
}
