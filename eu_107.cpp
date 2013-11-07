#include <cstdio>
#include <algorithm>
using namespace std;
const int n=40,inf=1<<30;
int c[50],a[50][50];
bool vis[50];
int main()
{
    int tot=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            while (1)
            {
                char ch=getchar();
                if (ch==',' || ch=='\n')
                    break;
                if (ch=='-')
                    a[i][j]=inf;
                else
                    a[i][j]=a[i][j]*10+ch-'0';
            }
            if (a[i][j]!=inf)
                tot+=a[i][j];
        }
    tot>>=1;
    for (int i=0;i<=n;i++)
        c[i]=inf;
    c[1]=0;
    for (int i=1;i<=n;i++)
    {
        int k=0;
        for (int j=1;j<=n;j++)
            if (!vis[j] && c[j]<c[k])
                k=j;
        vis[k]=true;
        tot-=c[k];
        for (int j=1;j<=n;j++)
            c[j]=min(c[j],a[k][j]);
    }
    printf("%d\n",tot);
    return(0);
}

