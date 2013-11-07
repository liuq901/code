#include <cstdio>
#include <queue>
using namespace std;
queue <int> Q[2];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int limit,n;
        scanf("%d%d",&limit,&n);
        limit*=100;
        for (int i=1;i<=n;i++)
        {
            char buf[100];
            int x;
            scanf("%d%s",&x,buf);
            Q[buf[0]=='r'].push(x);
        }
        int ans=0,now=0;
        while (!Q[0].empty() || !Q[1].empty())
        {
            int k=limit;
            while (!Q[now].empty() && k>=Q[now].front())
            {
                k-=Q[now].front();
                Q[now].pop();
            }
            ans++;
            now^=1;
        }
        printf("%d\n",ans);
    }
    return(0);
}

