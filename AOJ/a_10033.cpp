#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char op[100];
stack <char> s[1010];
int main()
{
    scanf("%*d");
    while (1)
    {
        scanf("%s",op);
        if (strcmp(op,"quit")==0)
            break;
        if (strcmp(op,"push")==0)
        {
            char ch;
            int x;
            scanf("%d %c",&x,&ch);
            s[x].push(ch);
        }
        else if (strcmp(op,"pop")==0)
        {
            int x;
            scanf("%d",&x);
            printf("%c\n",s[x].top());
            s[x].pop();
        }
        else
        {
            int x,y;
            scanf("%d%d",&x,&y);
            s[y].push(s[x].top());
            s[x].pop();
        }
    }
    return(0);
}

