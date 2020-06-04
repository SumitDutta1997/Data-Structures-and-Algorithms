// Evaluation of postfix expression

#include<iostream>
#include<stack>
using namespace std;

int isOperand(char);

void Evaluation(string postfix)
{
    stack<char>s;
    for(int i=0 ; postfix[i] != '\0' ; i++)
    {
        if(isOperand(postfix[i]))
            s.push(postfix[i]-'0');
        else
        {
            int x2 = s.top(); s.pop();
            int x1 = s.top(); s.pop();
            int result;
            switch(postfix[i])
            {
                case '+' : result = x1+x2 ; s.push(result) ; break;
                case '-' : result = x1-x2 ; s.push(result) ; break;
                case '*' : result = x1*x2 ; s.push(result) ; break;
                case '/' : result = x1/x2 ; s.push(result) ; break;
            }
        }
    }
    cout << s.top() << endl;
}

int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
}

int main()
{
    char postfix[50];
    cout << "Postfix Expression : ";
    cin >> postfix;
    Evaluation(postfix);

    return 0;
}
