#include<stdio.h>
#include<ctype.h>
char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
void intopost(char *e)
{  	int j=0;
	char x,p[100];
    while(*e != '\0')
    {
        if(isalnum(*e))
            p[j++]=*e;
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                p[j++]=x;
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                p[j++]=pop();
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        p[j++]=pop();
    }
    printf("Postfix expression: %s",p);    
}
int main()
{
    char exp[100];
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    intopost(exp);
	return 0;
}
