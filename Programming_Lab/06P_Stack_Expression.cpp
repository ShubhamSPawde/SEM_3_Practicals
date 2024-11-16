#include <bits/stdc++.h>
using namespace std;
#define SIZE 100

class Stack
{
    string st[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    string pop();
    string peep();
    void display();
    void push(string x);
    bool isEmpty();
    bool isFull();
};

class expression
{
    string postfix, infix, prefix;
    Stack s;

public:
    bool isoperator(char ch);
    int opprecedence(string ch);
    void prefix_to_infix();
    void infix_to_post();
    void post_eval();
};

bool expression::isoperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

int expression::opprecedence(string c)
{
    if (c[0] == '^')
    {
        return 3;
    }
    if (c[0] == '*' || c[0] == '%')
    {
        return 2;
    }
    if (c[0] == '+' || c[0] == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void expression::prefix_to_infix()
{
    cout << "Enter string: ";
    cin >> prefix;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isoperator(prefix[i]))
        {
            string op1 = s.pop();
            string op2 = s.pop();
            string temp = "(" + op1 + prefix[i] + op2 + ")";
            s.push(temp);
        }
        else
        {
            s.push(string(1, prefix[i]));
        }
    }
    cout << "Infix: " << s.pop() << endl;
}

void expression::infix_to_post()
{
    cout << "Enter Infix String: ";
    cin >> infix;
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            s.push("(");
        }
        else if (isoperator(infix[i]) == false && infix[i] != '(' && infix[i] != ')')
        {
            postfix += infix[i];
        }
        else if (infix[i] == ')')
        {
            while (s.peep() != "(" && !s.isEmpty())
            {
                string temp = s.pop();
                postfix += temp;
            }
            s.pop();
        }
        else
        {
            while (opprecedence(string(1, infix[i])) <= opprecedence(s.peep()) && !s.isEmpty())
            {
                string temp = s.pop();
                postfix += temp;
            }
            s.push(string(1, infix[i]));
        }
    }
    while (!s.isEmpty())
    {
        string temp = s.pop();
        postfix += temp;
    }
    cout << "Postfix: " << postfix << endl;
}
int postfixEvaluate(string str){

	stack<int> st;

	for (int i = 0; i < str.length(); i++)
	{
		if(str[i] >= '0' && str[i] <= '9'){
			st.push(str[i]-'0');
		}
		else{
			int op2 = st.top();
			st.pop();
			int op1 = st.top();
			st.pop();
			switch (str[i])
			{
			case '+':
				st.push(op1 + op2);
				break;
			case '-':
				st.push(op1 - op2);
				break;
			case '*':
				st.push(op1 * op2);
				break;
			case '/':
				st.push(op1 / op2);
				break;
			default:
				break;
			}
		}
	}

	return st.top();
	
}
void expression::post_eval()
{
    cout << "Enter postfix expression (space-separated): ";
    string input;
    cin.ignore();
    getline(cin, input);

    stringstream ss(input);
    string token;

    while (ss >> token)
    {
        if (isoperator(token[0]) && token.length() == 1)
        {
            string op2 = s.pop();
            string op1 = s.pop();

            stringstream ss1(op1);
            stringstream ss2(op2);
            int op_1, op_2;

            ss1 >> op_1;
            ss2 >> op_2;

            int res;
            switch (token[0])
            {
            case '+':
                res = op_1 + op_2;
                break;
            case '-':
                res = op_1 - op_2;
                break;
            case '*':
                res = op_1 * op_2;
                break;
            case '/':
                res = op_1 / op_2;
                break;
            case '^':
                res = pow(op_1, op_2);
                break;
            default:
                cout << "Invalid operator" << endl;
                return;
            }

            stringstream resultStream;
            resultStream << res;
            s.push(resultStream.str());
        }
        else
        {
            s.push(token);
        }
    }
    cout << "Result: " << s.pop() << endl;
}

string Stack::pop()
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
        return "";
    }
    return st[top--];
}

string Stack::peep()
{
    return st[top];
}

bool Stack::isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
    return top == SIZE - 1;
}

void Stack::push(string x)
{
    if (isFull())
    {
        cout << "Stack is Full!" << endl;
        return;
    }
    st[++top] = x;
}

void Stack::display()
{
    if (isEmpty())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        cout << st[i] << endl;
    }
}

int main()
{
    int choice;
    expression exp1;
    do
    {
        cout << "1. Prefix to Infix" << endl;
        cout << "2. Infix to Postfix" << endl;
        cout << "3. Evaluate Postfix" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            exp1.prefix_to_infix();
            cout << endl;
            break;
        case 2:
            exp1.infix_to_post();
            cout << endl;
            break;
        case 3:
            exp1.post_eval();
            cout << endl;
            break;
        case 10:
            return 0;
        }
    } while (choice != 10);
}
