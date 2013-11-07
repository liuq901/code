#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int m=300;
struct data
{
    int Add,add,Min,broke,size,a[m+10];
    bool f[m+10];
};
data a[350];
int move[m+10];
void update(int x)
{
    for (int i=1;i<=a[x].size;i++)
    {
        move[i]=max(0,a[x].Min-a[x].a[i]);
        a[x].a[i]=max(a[x].a[i],a[x].Min);
        a[x].a[i]+=a[x].add;
    }
    a[x].Min+=a[x].add;
    a[x].add=0;
    if (a[x].broke==1)
    {
        for (int i=1;i<=a[x].size;i++)
            if (a[x].a[i]-a[x].Add-move[i]<=0)
                a[x].f[i]=true;
        a[x].broke=2;
    }
}
void build(int n,int value)
{
    int t=0;
    while (1)
    {
        t++;
        a[t].Add=a[t].add=a[t].broke=0;
        memset(a[t].f,0,sizeof(a[t].f));
        a[t].Min=value;
        if (n<=m)
        {
            for (int i=1;i<=n;i++)
                a[t].a[i]=value;
            a[t].size=n;
            break;
        }
        for (int i=1;i<=m;i++)
            a[t].a[i]=value;
        a[t].size=m;
        n-=m;
    }
}
bool pass(int l,int r)
{
    int k;
    for (k=1;;k++)
    {
        if (l<=a[k].size)
            break;
        l-=a[k].size,r-=a[k].size;
    }
    update(k);
    if (r<=a[k].size)
    {
        for (int i=l;i<=r;i++)
            if (a[k].f[i])
                return(false);
        return(true);
    }
    for (int i=l;i<=a[k].size;i++)
        if (a[k].f[i])
            return(false);
    r-=a[k].size;
    k++;
    for (;;k++)
    {
        if (r<=a[k].size)
            break;
        if (a[k].broke>0)
            return(false);
        r-=a[k].size;
    }
    update(k);
    for (int i=1;i<=r;i++)
        if (a[k].f[i])
            return(false);
    return(true);
}
void broke(int l,int r,int value)
{
    int k;
    for (k=1;;k++)
    {
        if (l<=a[k].size)
            break;
        l-=a[k].size,r-=a[k].size;
    }
    update(k);
    if (r<=a[k].size)
    {
        for (int i=l;i<=r;i++)
        {
            a[k].a[i]-=value;
            if (a[k].a[i]<=0)
            {
                a[k].broke=2;
                a[k].f[i]=true;
            }
            a[k].Min=min(a[k].Min,a[k].a[i]);
        }
        return;
    }
    for (int i=l;i<=a[k].size;i++)
    {
        a[k].a[i]-=value;
        if (a[k].a[i]<=0)
        {
            a[k].broke=2;
            a[k].f[i]=true;
        }
        a[k].Min=min(a[k].Min,a[k].a[i]);
    }
    r-=a[k].size;
    k++;
    for (;;k++)
    {
        if (r<=a[k].size)
            break;
        a[k].add-=value;
        if (a[k].Min+a[k].add<=0)
        {
            a[k].broke=1;
            a[k].Add=0;
        }
        r-=a[k].size;
    }
    update(k);
    for (int i=1;i<=r;i++)
    {
        a[k].a[i]-=value;
        if (a[k].a[i]<=0)
        {
            a[k].broke=2;
            a[k].f[i]=true;
        }
        a[k].Min=min(a[k].Min,a[k].a[i]);
    }
}
void updata(int x)
{
    a[x].Min=a[x].a[1];
    for (int i=2;i<=a[x].size;i++)
        a[x].Min=min(a[x].Min,a[x].a[i]);
}
void add(int l,int r,int value)
{
    int k;
    for (k=1;;k++)
    {
        if (l<=a[k].size)
            break;
        l-=a[k].size,r-=a[k].size;
    }
    update(k);
    if (r<=a[k].size)
    {
        for (int i=l;i<=r;i++)
            a[k].a[i]+=value;
        updata(k);
        return;
    }
    for (int i=l;i<=a[k].size;i++)
        a[k].a[i]+=value;
    updata(k);
    r-=a[k].size;
    k++;
    for (;;k++)
    {
        if (r<=a[k].size)
            break;
        a[k].add+=value;
        a[k].Add+=value;
        r-=a[k].size;
    }
    update(k);
    for (int i=1;i<=r;i++)
        a[k].a[i]+=value;
    updata(k);
}
void Set(int l,int r,int value)
{
    int k;
    for (k=1;;k++)
    {
        if (l<=a[k].size)
            break;
        l-=a[k].size,r-=a[k].size;
    }
    update(k);
    if (r<=a[k].size)
    {
        for (int i=l;i<=r;i++)
            a[k].a[i]=max(a[k].a[i],value);
        updata(k);
        return;
    }
    for (int i=l;i<=a[k].size;i++)
        a[k].a[i]=max(a[k].a[i],value);
    updata(k);
    r-=a[k].size;
    k++;
    for (;;k++)
    {
        if (r<=a[k].size)
            break;
        a[k].Min=max(a[k].Min,value-a[k].add);
        r-=a[k].size;
    }
    update(k);
    for (int i=1;i<=r;i++)
        a[k].a[i]=max(a[k].a[i],value);
    updata(k);
}
int main()
{
    while (1)
    {
        int n,m,I;
        scanf("%d%d%d",&n,&m,&I);
        if (!n && !m && !I)
            break;
        build(n,I);
        int ans=0;
        for (int i=1;i<=m;i++)
        {
            int op,x,y,z;
            scanf("%d%d%d%d",&op,&x,&y,&z);
            if (op==1)
            {
                if (!pass(x,y))
                    continue;
                ans++;
                broke(x,y,z);
            }
            else if (op==2)
                add(x,y,z);
            else
                Set(x,y,z);
        }
        printf("%d\n",ans);
    }
    return(0);
}

