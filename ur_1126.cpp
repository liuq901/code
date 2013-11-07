#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
priority_queue <pair <int,int> > Q;
int main()
{
    int n,t=0;
    scanf("%d",&n);
    while (1)
    {
        int x;
        scanf("%d",&x);
        if (x==-1)
            break;
        Q.push(make_pair(x,++t));
        if (t>=n)
        {
            while (Q.top().second<=t-n)
                Q.pop();
            printf("%d\n",Q.top());
        }
    }
    return(0);
}

