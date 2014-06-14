#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int pos[110],choose[110],boy[110][110],girl[110][110];
queue <int> Q;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                int x;
                scanf("%d",&x);
                boy[i][j]=x-n;
            }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                int x;
                scanf("%d",&x);
                girl[i][x]=j;
            }
        for (int i=1;i<=n;i++)
        {
            pos[i]=choose[i]=0;
            Q.push(i);
        }
        while (!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            int y=boy[x][++pos[x]];
            if (choose[y]==0)
                choose[y]=x;
            else
            {
                int t=choose[y];
                if (girl[y][t]<girl[y][x])
                    swap(x,t);
                choose[y]=x;
                Q.push(t);
            }
        }
        static int id=0;
        printf("Case %d:",++id);
        for (int i=1;i<=n;i++)
            printf(" (%d %d)",choose[i],i+n);
        printf("\n");
    }
}

