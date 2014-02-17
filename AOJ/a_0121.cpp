#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int a[10],q[40300],f[40330],to[40330];
map <int,int> M;
void generate()
{
    for (int i=1;i<=8;i++)
        a[i]=i-1;
    int t=0;
    while (1)
    {
        int p=0;
        for (int i=1;i<=8;i++)
           p=p*10+a[i];
        M[p]=++t;
        to[t]=p;
        if (!next_permutation(a+1,a+9))
            break;
    }
}
int encode()
{
    int p=0;
    for (int i=1;i<=8;i++)
        p=p*10+a[i];
    return(M[p]);
}
void decode(int n)
{
    int p=to[n];
    for (int i=8;i;i--)
    {
        a[i]=p%10;
        p/=10;
    }
}
void init()
{
    generate();
    for (int i=1;i<=8;i++)
        a[i]=i-1;
    int l,r,t=encode();
    q[l=r=1]=t;
    f[t]=1;
    while (l<=r)
    {
        int x=q[l++],pos;
        decode(x);
        for (int i=1;i<=8;i++)
            if (a[i]==0)
            {
                pos=i;
                break;
            }
        if (pos!=1 && pos!=5)
        {
            swap(a[pos],a[pos-1]);
            int y=encode();
            if (f[y]==0)
            {
                f[y]=f[x]+1;
                q[++r]=y;
            }
            swap(a[pos],a[pos-1]);
        }
        if (pos!=4 && pos!=8)
        {
            swap(a[pos],a[pos+1]);
            int y=encode();
            if (f[y]==0)
            {
                f[y]=f[x]+1;
                q[++r]=y;
            }
            swap(a[pos],a[pos+1]);            
        }
        if (pos<=4)
        {
            swap(a[pos],a[pos+4]);
            int y=encode();
            if (f[y]==0)
            {
                f[y]=f[x]+1;
                q[++r]=y;
            }
            swap(a[pos],a[pos+4]);
        }
        else
        {
            swap(a[pos],a[pos-4]);
            int y=encode();
            if (f[y]==0)
            {
                f[y]=f[x]+1;
                q[++r]=y;
            }
            swap(a[pos],a[pos-4]);            
        }
    }
}
int main()
{
    init();
    while (scanf("%d",&a[1])==1)
    {
        for (int i=2;i<=8;i++)
            scanf("%d",&a[i]);
        printf("%d\n",f[encode()]-1);
    }
    return(0);
}

