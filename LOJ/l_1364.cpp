#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int A,B,C,D,vis[20][20][20][20][5][5];
double f[20][20][20][20][5][5];
bool ok(int a,int b,int c,int d,int small,int big)
{
    a+=(small==1)+(big==1);
    b+=(small==2)+(big==2);
    c+=(small==3)+(big==3);
    d+=(small==4)+(big==4);
    return(a>=A && b>=B && c>=C && d>=D);
}
double solve(int a,int b,int c,int d,int small,int big)
{
    if (vis[a][b][c][d][small][big])
        return(f[a][b][c][d][small][big]);
    vis[a][b][c][d][small][big]=true;
    double &ret=f[a][b][c][d][small][big];
    ret=0;
    if (!ok(a,b,c,d,small,big))
    {
        int tot=13-a+13-b+13-c+13-d+!small+!big;
        if (!tot)
        {
            ret=1e100;
            goto last;
        }
        if (13-a)
            ret+=solve(a+1,b,c,d,small,big)*(13-a)/tot;
        if (13-b)
            ret+=solve(a,b+1,c,d,small,big)*(13-b)/tot;
        if (13-c)
            ret+=solve(a,b,c+1,d,small,big)*(13-c)/tot;
        if (13-d)
            ret+=solve(a,b,c,d+1,small,big)*(13-d)/tot;
        if (!small)
        {
            double tmp=1e100;
            for (int i=1;i<=4;i++)
                tmp=min(tmp,solve(a,b,c,d,i,big));
            ret+=tmp*1/tot;
        }
        if (!big)
        {
            double tmp=1e100;
            for (int i=1;i<=4;i++)
                tmp=min(tmp,solve(a,b,c,d,small,i));
            ret+=tmp*1/tot;
        }
        ret++;
    }
last:
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d%d",&A,&B,&C,&D);
        static int id=0;
        printf("Case %d: ",++id);
        int extra=max(0,A-13)+max(0,B-13)+max(0,C-13)+max(0,D-13);
        if (extra>2)
            printf("-1\n");
        else
        {
            memset(vis,0,sizeof(vis));
            printf("%.10f\n",solve(0,0,0,0,0,0));
        }
    }
    return(0);
}

