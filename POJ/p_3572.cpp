#include <cstdio>
typedef long long ll;
struct state
{
    int id;
    ll step;
};
bool vis[10][40];
state f[10][40];
int a[10][10];
state move(int id,int n)
{
    if (vis[id][n])
        return(f[id][n]);
    vis[id][n]=true;
    state &ret=f[id][n];
    if (n==1)
    {
        int k=-1;
        for (int i=0;i<3;i++)
            if (i!=id && (k==-1 || a[id][i]<a[id][k]))
                k=i;
        ret.id=k;
        ret.step=1;
    }
    else
    {
        state now=move(id,n-1);
        int cur=id;
        ret.step=now.step;
        bool flag=true;
        while (cur!=now.id)
        {
            int other=3-cur-now.id;
            if (flag)
            {
                cur=other;
                ret.step++;
                flag=false;
            }
            else
            {
                flag=true;
                now=move(now.id,n-1);
                ret.step+=now.step;
            }
        }
        ret.id=cur;
    }
    return(ret);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=6;i++)
    {
        char x,y;
        scanf(" %c%c",&x,&y);
        a[x-'A'][y-'A']=i;
    }
    printf("%I64d\n",move(0,n).step);
    return(0);
}

