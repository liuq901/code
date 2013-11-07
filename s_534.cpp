#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int tot=1,fur,to[100010],b[100010],d[100010],p[100010],f[100010][2],a[200010][4];
vector <int> ans;
inline void add(int x,int y,int z,int p)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=p,a[tot][3]=b[x],b[x]=tot;
}
void dfs(int x,int father)
{
    for (int i=b[x];i;i=a[i][3])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        d[y]=d[x]+a[i][1];
        dfs(y,x);
    }
}
inline bool cmp(int x,int y)
{
    return(p[x]>p[y]);
}
void dp(int x,int father)
{
    vector <int> c;
    for (int i=b[x];i;i=a[i][3])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dp(y,x);
        p[y]=d[y]+a[i][1];
        c.push_back(y);
    }
    if (c.size()==0)
    {
        f[x][0]=1<<30;
        f[x][1]=0;
        d[x]=0;
        return;
    }
    sort(c.begin(),c.end(),cmp);
    d[x]=p[c[0]];
    f[x][0]=0;
    for (int i=b[x];i;i=a[i][3])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        if (p[y]==d[x])
            f[x][0]+=min(f[y][0],f[y][1]+a[i][2]);
        else
            f[x][0]+=f[y][1];
    }
    f[x][1]=0;
    if (c.size()>=2 && p[c[0]]+p[c[1]]==fur)
        if (p[c[0]]!=p[c[1]])
            for (int i=b[x];i;i=a[i][3])
            {
                int y=a[i][0];
                if (y==father)
                    continue;
                if (p[y]==p[c[1]])
                    f[x][1]+=min(f[y][0],f[y][1]+a[i][2]);
                else
                    f[x][1]+=f[y][1];
            }
        else
        {
            int u=0;
            for (int i=b[x];i;i=a[i][3])
            {
                int y=a[i][0];
                if (y==father)
                    continue;
                if (p[y]==d[x])
                {
                    int t=min(f[y][0],f[y][1]+a[i][2]);
                    if (t-f[y][1]>u)
                    {
                        u=t-f[y][1];
                        to[x]=y;
                    }
                    f[x][1]+=t;
                }
                else
                    f[x][1]+=f[y][1];
            }
            f[x][1]-=u;
        }
    else
        for (int i=b[x];i;i=a[i][3])
        {
            int y=a[i][0];
            if (y==father)
                continue;
            f[x][1]+=f[y][1];
        }
    f[x][1]=min(f[x][1],f[x][0]);
}
void print(int x,int op,int father)
{
    if (op==1 && f[x][1]==f[x][0])
        op=0;
    if (op==0)
        for (int i=b[x];i;i=a[i][3])
        {
            int y=a[i][0];
            if (y==father)
                continue;
            if (p[y]==d[x])
                if (f[y][0]<f[y][1]+a[i][2])
                    print(y,0,x);
                else
                {
                    print(y,1,x);
                    ans.push_back(i/2);
                }
            else
                print(y,1,x);
        }
    else
    {
        vector <int> c;
        for (int i=b[x];i;i=a[i][3])
        {
            int y=a[i][0];
            if (y==father)
                continue;
            c.push_back(y);
        }
        sort(c.begin(),c.end(),cmp);
        if (c.size()>=2 && p[c[0]]+p[c[1]]==fur)
            if (p[c[0]]!=p[c[1]])
                for (int i=b[x];i;i=a[i][3])
                {
                    int y=a[i][0];
                    if (y==father)
                        continue;
                    if (p[y]==p[c[1]])
                        if (f[y][0]<f[y][1]+a[i][2])
                            print(y,0,x);
                        else
                        {
                            print(y,1,x);
                            ans.push_back(i/2);
                        }
                    else
                        print(y,1,x);
                }
            else
                for (int i=b[x];i;i=a[i][3])
                {
                    int y=a[i][0];
                    if (y==father)
                        continue;
                    if (p[y]==d[x] && y!=to[x])
                        if (f[y][0]<f[y][1]+a[i][2])
                            print(y,0,x);
                        else
                        {
                            print(y,1,x);
                            ans.push_back(i/2);
                        }
                    else
                        print(y,1,x);
                }
        else
            for (int i=b[x];i;i=a[i][3])
            {
                int y=a[i][0];
                if (y==father)
                    continue;
                print(y,1,x);
            }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int x,y,z,q;
        scanf("%d%d%d%d",&x,&y,&z,&q);
        p[x]++,p[y]++;
        add(x,y,z,q);
        add(y,x,z,q);
    }
    if (n==2)
    {
        printf("%d\n1\n1\n",a[2][2]);
        return(0);
    }
    d[1]=0;
    dfs(1,0);
    int k=0;
    for (int i=1;i<=n;i++)
        if (d[i]>d[k])
            k=i;
    d[k]=0;
    dfs(k,0);
    for (int i=1;i<=n;i++)
        fur=max(fur,d[i]);
    for (int i=1;i<=n;i++)
        if (p[i]>1)
        {
            k=i;
            break;
        }
    dp(k,0);
    printf("%d\n",f[k][1]);
    print(k,1,0);
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    return(0);
}

