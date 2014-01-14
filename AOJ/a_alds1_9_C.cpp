#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    priority_queue <int> Q;
    while (1)
    {
        char op[10];
        scanf("%s",op);
        if (op[0]=='i')
        {
            int x;
            scanf("%d",&x);
            Q.push(x);
        }
        else if (op[1]=='x')
        {
            printf("%d\n",Q.top());
            Q.pop();
        }
        else
            break;
    }
    return(0);
}

