#include <cstdio>
#include <queue>
using namespace std;
struct state
{
    int l,r,step;
    state(int l,int r,int step):l(l),r(r),step(step){}
};
char buf[1000];
int a[20],f[10010];
int sign(int x)
{
    return(x<0?-1:x>0);
}
int bfs(int root)
{
    queue <state> Q;
    for (int i=1;;i++)
    {
        int l=root-i,r=root+i;
        if (l<0 || r>10000)
            break;
        if (f[l]*f[r]==-1)
            Q.push(state(l,r,1));
    }
    int ans=0;
    while (!Q.empty())
    {
        ans++;
        int l=Q.front().l,r=Q.front().r,step=Q.front().step;
        Q.pop();
        if (step==7)
            continue;
        int now=2*l-r;
        if (now>=0 && f[now]*f[r]==-1)
            Q.push(state(now,r,step+1));
        now=2*r-l;
        if (now<=10000 && f[now]*f[l]==-1)
            Q.push(state(l,now,step+1));
    }
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n=0,x;
        gets(buf);
        while (scanf("(x-%d)",&x)==1)
            a[++n]=x;
        gets(buf);
        int root;
        scanf("%d",&root);
        for (int i=0;i<=10000;i++)
        {
            f[i]=1;
            for (int j=1;j<=n;j++)
                f[i]*=sign(i-a[j]);
        }
        printf("%d\n",bfs(root));
    }
    return(0);
}

