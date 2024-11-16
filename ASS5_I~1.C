#include <stdio.h>
#include<conio.h>

void push(int opeArray[], char infix, int *top) 
{
  *top += 1;
  opeArray[*top] = infix;
}

int priority(char value)
{
  int priority;
  if (value == '*' || value == '/') {
    priority = 2;
  } else if (value == '+' || value == '-') {
    priority = 1;
  } else if (value == ')' || value == '(') {
    priority = 0;
  }

  return priority;
}

char pop(int opeArray[], int *top)
 {
  char value;
  value = opeArray[*top];
  *top -= 1;
  return value;
}

void main()
{
  int opeArray[10], i = 0, x = -1, *top = &x;
  char infix[100], value;

  printf("Enter the Infix Expression : ");
  scanf("%s", infix);

  while (infix[i] != '\0')
  {
    if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' ||infix[i] == '/') {
      if (*top == -1)
       {
	push(opeArray, infix[i], top);
      } else

      {
	while (priority(opeArray[*top]) >= priority(infix[i]) && opeArray[*top] != '(' && *top != -1)
	{
	  value = pop(opeArray, top);
	  printf("%c", value);
	}
	push(opeArray, infix[i], top);
      }
    } else if (infix[i] == '(')
     {
      push(opeArray, infix[i], top);
    } else if (infix[i] == ')')
     {
      while (opeArray[*top] != '(')
       {
	value = pop(opeArray, top);
	printf("%c", value);
      }
      value = pop(opeArray,top);
    }
    else if (infix[i] >= 'A' && infix[i] <= 'Z' ||infix[i] >= 'a' && infix[i] <= 'z')
	       {
	      printf("%c", infix[i]);
    }
    i += 1;
  }
  while (*top != -1)
  {
    value = pop(opeArray, top);
    printf("%c", value);
  }
  getch();
}