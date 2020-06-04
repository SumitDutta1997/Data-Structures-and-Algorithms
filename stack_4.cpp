// infix to postfix

#include<iostream>
#include<stack>
using namespace std;

int isOperand(char);
int Precedence(char);

void InfixToPostfix(string infix)
{
    stack<char>s;
    //s.push('$');
    char postfix[infix.length()];

    int i=0 , j=0;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(s.empty())
                s.push(infix[i++]);
            else if(Precedence(infix[i]) > Precedence(s.top()))
               s.push(infix[i++]);
            else
            {
                postfix[j++] = s.top();
                s.pop();
            }
        }
    }
    while(!s.empty())
    {
        postfix[j++] = s.top();
        s.pop();
    }
    postfix[j] = '\0';
    cout << endl << "postfix expression : " << postfix << endl;
}

int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
}

int Precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    else
        return 0;
}

int main()
{
    char infix[50];
    cout << "infix expression : ";
    cin >> infix;
    InfixToPostfix(infix);

    return 0;
}
