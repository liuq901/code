#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char op[100];
stack <char> s;
int main()
{
    while (1)
    {
        scanf("%s",op);
        if (strcmp(op,"quit")==0)
            break;
        if (strcmp(op,"push")==0)
        {
            char ch;
            scanf(" %c",&ch);
            s.push(ch);
        }
        else
        {
            printf("%c\n",s.top());
            s.pop();
        }
    }
    return(0);
}

