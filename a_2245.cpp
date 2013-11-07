#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int c[4][7]={{0,6,2,5,4,1,3},{0,5,2,6,4,3,1},{0,1,6,3,5,2,4},{0,1,5,3,6,4,2}};
const int p[7][4]={{},{2,5,4,6},{3,5,1,6},{4,5,2,6},{1,5,3,6},{2,3,4,1},{2,1,4,3}};
bool f[10][10],flag[700010];
char a[10][10][10];
int d[700010],ans[700010][3];
queue <int> Q;
int hash(int *b)
{
    int x=0;
    for (int i=1;i<=6;i++)
        x=x*10+b[i];
    return(x);
}
void init()
{
    Q.push(123456);
    d[123456]=0;
    flag[123456]=true;
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        int a[10],tmp=x;
        for (int i=6;i;i--)
        {
            a[i]=tmp%10;
            tmp/=10;
        }
        ans[x][0]=a[1],ans[x][1]=a[3],ans[x][2]=a[6];
        for (int i=0;i<4;i++)
        {
            int b[10];
            for (int j=1;j<=6;j++)
                b[j]=a[c[i][j]];
            int t=hash(b);
            if (!flag[t])
            {
                flag[t]=true;
                d[t]=d[x]+1;
                Q.push(t);
            }
        }
    }
}
void calc(int x)
{
    for (int i=1;i<=3;i++)
    {
        if (a[x][i][3]=='*')
            f[x][p[x][0]]=true;
        if (a[x][1][i]=='*')
            f[x][p[x][1]]=true;
        if (a[x][i][1]=='*')
            f[x][p[x][2]]=true;
        if (a[x][3][i]=='*')
            f[x][p[x][3]]=true;
    }
}
bool check(int t)
{
    return(f[ans[t][0]][ans[t][2]] && f[ans[t][1]][ans[t][2]]);
}
int main()
{
    init();
    while (1)
    {
        scanf("%s",a[1][1]+1);
        if (a[1][1][1]=='#')
            break;
        scanf("%s%s",a[1][2]+1,a[1][3]+1);
        for (int i=2;i<=6;i++)
            for (int j=1;j<=3;j++)
                scanf("%s",a[i][j]+1);
        memset(f,0,sizeof(f));
        for (int i=1;i<=6;i++)
            calc(i);
        int b[10];
        for (int i=1;i<=6;i++)
            b[i]=i;
        int Ans=1<<30;
        while (1)
        {
            int t=hash(b);
            if (flag[t] && check(t))
                Ans=min(Ans,d[t]); 
            if (!next_permutation(b+1,b+7))
                break;
        }
        printf("%d\n",Ans);
    }
    return(0);
}

