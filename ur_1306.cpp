#include <cstdio>
#include <queue>
using namespace std;
priority_queue <int> Q;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        Q.push(x);
        if (i>n/2)
            Q.pop();
    }
    if (n%2==1)
        printf("%d.0\n",Q.top());
    else
    {
        int x=Q.top();
        Q.pop();
        printf("%.1f\n",(Q.top()+double(x))/2.0);
    }
    return(0);
}

