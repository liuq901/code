#include <cstdio>
typedef long long ll;
const int m=500;
struct data
{
    ll allA,allB,s,a[m+10];
    int tA,tB,C;
};
data a[510];
int calc(int x)
{
    if (a[x].C!=26262626)
    {
        for (int i=0;i<m;i++)
            a[x].a[i]=a[x].C;
        a[x].C=26262626;
    }
    for (int i=0;i<m;i++)
        a[x].a[i]+=a[x].allA+a[x].allB+(a[x].tA-a[x].tB)*i;
    a[x].allA=a[x].allB=a[x].tA=a[x].tB=0;
}
void A(int st,int nd)
{
    int l=st/m,r=nd/m,l1=st%m,r1=nd%m,v=1;
    if (l==r)
    {
        calc(l);
        for (int i=l1;i<=r1;i++)
        {
            a[l].a[i]+=v;
            a[l].s+=v;
            v++;
        }
        return;
    }
    calc(l);
    for (int i=l1;i<m;i++)
    {
        a[l].a[i]+=v;
        a[l].s+=v;
        v++;
    }
    for (int i=l+1;i<r;i++)
    {
        a[i].allA+=v;
        a[i].tA++;
        a[i].s+=ll(2*v+m-1)*m/2;
        v+=m;
    }
    calc(r);
    for (int i=0;i<=r1;i++)
    {
        a[r].a[i]+=v;
        a[r].s+=v;
        v++;
    }
}
void B(int st,int nd)
{
    int l=st/m,r=nd/m,l1=st%m,r1=nd%m,v=nd-st+1;
    if (l==r)
    {
        calc(l);
        for (int i=l1;i<=r1;i++)
        {
            a[l].a[i]+=v;
            a[l].s+=v;
            v--;
        }
        return;
    }
    calc(l);
    for (int i=l1;i<m;i++)
    {
        a[l].a[i]+=v;
        a[l].s+=v;
        v--;
    }
    for (int i=l+1;i<r;i++)
    {
        a[i].allB+=v;
        a[i].tB++;
        a[i].s+=ll(2*v-m+1)*m/2;
        v-=m;
    }
    calc(r);
    for (int i=0;i<=r1;i++)
    {
        a[r].a[i]+=v;
        a[r].s+=v;
        v--;
    }
}
void C(int st,int nd,int value)
{
    int l=st/m,r=nd/m,l1=st%m,r1=nd%m;
    if (l==r)
    {
        calc(l);
        for (int i=l1;i<=r1;i++)
        {
            a[l].s+=value-a[l].a[i];
            a[l].a[i]=value;
        }
        return;
    }
    calc(l);
    for (int i=l1;i<m;i++)
    {
        a[l].s+=value-a[l].a[i];
        a[l].a[i]=value;
    }
    for (int i=l+1;i<r;i++)
    {
        a[i].allA=a[i].allB=a[i].tA=a[i].tB=0;
        a[i].C=value;
        a[i].s=ll(value)*m;
    }
    calc(r);
    for (int i=0;i<=r1;i++)
    {
        a[r].s+=value-a[r].a[i];
        a[r].a[i]=value;
    }
}
ll S(int st,int nd)
{
    ll ans=0;
    int l=st/m,r=nd/m,l1=st%m,r1=nd%m;
    if (l==r)
    {
        calc(l);
        for (int i=l1;i<=r1;i++)
            ans+=a[l].a[i];
        return(ans);
    }
    calc(l);
    for (int i=l1;i<m;i++)
        ans+=a[l].a[i];
    //printf("%lld\n",ans);
    for (int i=l+1;i<r;i++)
        ans+=a[i].s;
    //printf("%lld\n",ans);
    calc(r);
    for (int i=0;i<=r1;i++)
        ans+=a[r].a[i];
    //printf("%lld\n",ans);
    //printf("=======\n");
    return(ans);
}
void print(ll x)
{
    if (x==0)
    {
        printf("0\n");
        return;
    }
    if (x<0)
    {
        printf("-");
        x=-x;
    }
    int a[30];
    a[0]=0;
    while (x)
    {
        a[++a[0]]=x%10;
        x/=10;
    }
    for (int i=a[0];i;i--)
        printf("%d",a[i]);
    printf("\n");
}
int main()
{
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        char op[10];
        int st,ed;
        scanf("%s%d%d",op,&st,&ed);
        if (op[0]=='A')
            A(st-1,ed-1);
        else if (op[0]=='B')
            B(st-1,ed-1);
        else if (op[0]=='C')
        {
            int x;
            scanf("%d",&x);
            C(st-1,ed-1,x);
        }
        else
            print(S(st-1,ed-1));
    }
    return(0);
}

