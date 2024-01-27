#include "FloatingPointStack.cpp"

int main()
{
	char postfix[20];
	Stack s;
	float result, n1, n2;
	int i = 0;
	cout << "***Evaluation of Postfix Expression***\n\n";
	cout << "Enter a postfix expression: \n";
	gets(postfix);
	while (postfix[i] != '\0')
	{
		if (postfix[i] == ' ')
		{
			i++;
			continue;
		}
		if (isdigit(postfix[i]))
		{
			float x;
			x = postfix[i] - 48.0; // 48.0 refers to the base value of ASCII Values
			s.Push(x);
		}
		else // It will be an operator
		{
			n2 = s.Pop();
			n1 = s.Pop();
			switch (postfix[i])
			{
			case '+':
				result = n1 + n2;
				break;
			case '-':
				result = n1 - n2;
				break;
			case '*':
				result = n1 * n2;
				break;
			case '/':
				result = n1 / n2;
				break;
			} // End of Switch
			s.Push(result);
		} // End Of postfix[i] is an operator
		i++;
	} // End Of While
	cout << "Result of postfix evaluation: " << s.Pop();
} // End of Main


