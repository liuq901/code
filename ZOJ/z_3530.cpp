#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int gold[1010],g[1010],a[1010],s[1010],c[1010],b[1010];
void calc(int sum,int &a,int &b)
{
    if (a>b)
        swap(a,b);
    int p=b-a;
    if (sum<=p)
    {
        a+=sum;
        return;
    }
    a=b,sum-=p;
    int x=sum>>1,y=sum-x;
    a+=x,b+=y;
}
int main()
{
    int n,F,W;
    while (scanf("%d%d%d%d",&n,&F,&W,&g[0])==4)
    {
        gold[0]=g[0];
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&s[i],&g[i]);
            if (s[i]<s[i-1])
                s[i]=s[i-1];
            gold[i]=gold[i-1]+g[i];
        }
        bool flag=true;
        for (int i=1;i<=n;i++)
        {
            a[i]=s[i]-s[i-1];
            if (gold[i-1]<s[i])
            {
                printf("It's useless to collect wood.\n");
                flag=false;
                break;
            }
        }
        if (!flag)
            continue;
        c[n]=0;
        for (int i=n-1;i>=0;i--)
            c[i]=max(c[i+1]-g[i+1],0)+a[i+1];
        int now=0,num=0,rate=W;
        ll ans=0;
        for (int i=0;i<=n-1;i++)
        {
            ans+=ll(num)*rate;
            now+=g[i];
            int p=(now-c[i])/F;
            calc(p,num,rate);
            now-=p*F+a[i+1];
        }
        ans+=ll(num)*rate;
        printf("%lld\n",ans);
    }
    return(0);
}

