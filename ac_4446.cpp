#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef int array[50];
array d,q,g,input,out,wrong;
char type[50],buf[100];
vector <int> IN[260],OUT[260];
int n,K,m,B,in[50][2];
int get()
{
    scanf("%s",buf);
    char ch;
    int x;
    sscanf(buf,"%c%d",&ch,&x);
    if (ch=='i')
        return(-x);
    else
        return(x);
}
void topsort()
{
    memset(d,0,sizeof(d));
    for (int i=1;i<=K;i++)
        for (int j=0;j<=1;j++)
            if (in[i][j]>0)
                d[in[i][j]]++;
    int l=1,r=0;
    for (int i=1;i<=K;i++)
        if (!d[i])
            q[++r]=i;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=0;i<=1;i++)
        {
            int y=in[x][i];
            if (y>0)
            {
                d[y]--;
                if (d[y]==0)
                    q[++r]=y;
            }
        }
    }
    reverse(q+1,q+K+1);
}
void work()
{
    for (int i=1;i<=K;i++)
    {
        int x=q[i],u,v;
        u=in[x][0]>0?g[in[x][0]]:input[-in[x][0]];
        v=in[x][1]>0?g[in[x][1]]:input[-in[x][1]];
        if (type[x]=='a')
            g[x]=u&v;
        else if (type[x]=='n')
            g[x]=!u;
        else if (type[x]=='o')
            g[x]=u|v;
        else
            g[x]=u^v;
        if (wrong[x]==1)
            g[x]=!g[x];
        else if (wrong[x]==2)
            g[x]=0;
        else if (wrong[x]==3)
            g[x]=1;
    }
}
bool check()
{
    for (int i=1;i<=B;i++)
    {
        for (int j=1;j<=n;j++)
            input[j]=IN[i][j];
        work();
        for (int j=1;j<=m;j++)
            if (g[out[j]]!=OUT[i][j])
                return(false);
    }
    return(true);
}
int main()
{
    while (1)
    {
        scanf("%d%d%d",&n,&K,&m);
        if (n==0 && K==0 && m==0)
            break;
        for (int i=1;i<=K;i++)
        {
            scanf("%s",buf);
            type[i]=buf[0];
            in[i][0]=get();
            if (type[i]=='n')
                in[i][1]=0;
            else
                in[i][1]=get();
        }
        for (int i=1;i<=m;i++)
            scanf("%d",&out[i]);
        scanf("%d",&B);
        for (int i=1;i<=B;i++)
        {
            IN[i].resize(n+1);
            OUT[i].resize(m+1);
            for (int j=1;j<=n;j++)
                scanf("%d",&IN[i][j]);
            for (int j=1;j<=m;j++)
                scanf("%d",&OUT[i][j]);
        }
        topsort();
        static int id=0;
        printf("Case %d: ",++id);
        memset(wrong,0,sizeof(wrong));
        if (check())
            printf("No faults detected\n");
        else
        {
            int sum=0,ans,kind;
            for (int i=1;i<=K;i++)
            {
                for (wrong[i]=1;wrong[i]<=3;wrong[i]++)
                    if (check())
                    {
                        sum++;
                        ans=i;
                        kind=wrong[i];
                        if (sum==2)
                            goto out;
                    }
                wrong[i]=0;
            }
out:
            if (sum==2)
                printf("Unable to totally classify the failure\n");
            else
            {
                printf("Gate %d is failing; output ",ans);
                if (kind==1)
                    printf("inverted\n");
                else
                    printf("stuck at %d\n",kind-2);
            }
        }
    }
    return(0);
}

