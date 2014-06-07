#include <cstdio>
#include <cstring>
typedef unsigned long long ull;
ull f[20][20][20][20][10];
bool vis[20][20][20][20][10];
int get(char ch)
{
    if (ch=='A')
        return(1);
    else if (ch=='T')
        return(10);
    else if (ch=='J')
        return(11);
    else if (ch=='Q')
        return(12);
    else if (ch=='K')
        return(13);
    else
        return(ch-'0');
}
ull dp(int x,int y,int z,int t,int prev)
{
    if (vis[x][y][z][t][prev])
        return(f[x][y][z][t][prev]);
    vis[x][y][z][t][prev]=true;
    ull &ret=f[x][y][z][t][prev];
    if (x+y+z+t==0)
        ret=1;
    else
    {
        ret=0;
        if (x)
            ret+=dp(x-1,y,z,t,0)*(x-(prev==1));
        if (y)
            ret+=dp(x+1,y-1,z,t,1)*(y-(prev==2))*2;
        if (z)
            ret+=dp(x,y+1,z-1,t,2)*(z-(prev==3))*3;
        if (t)
            ret+=dp(x,y,z+1,t-1,3)*t*4;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,a[20]={0};
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            char s[10];
            scanf("%s",s);
            a[get(s[0])]++;
        }
        int cnt[5]={0};
        for (int i=1;i<=13;i++)
            cnt[a[i]]++;
        static int id=0;
        printf("Case %d: %llu\n",++id,dp(cnt[1],cnt[2],cnt[3],cnt[4],0));
    }
    return(0);
}

