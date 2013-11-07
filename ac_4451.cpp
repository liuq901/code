#include <cstdio>
#include <algorithm>
using namespace std;
struct card
{
    int num;
    char suit;
    bool empty()
    {
        return(num==0);
    }
    void clear()
    {
        num=0;
    }
    void in()
    {
        scanf("%d%c",&num,&suit);
    }
};
char player[100];
card hr,hb,deck[30],a[10][10];
int n,s1[10],s2[10];
int getscore()
{
    int ret=0;
    if (!hr.empty())
        ret+=(hr.suit=='R'?1:-1)*hr.num;
    if (!hb.empty())
        ret+=(hb.suit=='R'?1:-1)*hb.num;
    return(ret);
}
int get(const card &a,const card &b,const card &c)
{
    int score=a.num+b.num+c.num,sum=0;
    sum+=(a.suit=='R')+(b.suit=='R')+(c.suit=='R');
    if (sum>=2)
        return(score);
    else
        return(-score);
}
void del(int *a,int x)
{
    int k;
    for (int i=1;i<=a[0];i++)
        if (a[i]==x)
        {
            k=i;
            break;
        }
    for (int i=k+1;i<=a[0];i++)
        a[i-1]=a[i];
    a[0]--;
}
int dfs(int dep,bool red)
{
    if (dep==n+1)
        return(getscore());
    card &hand=red?hr:hb,now=deck[dep],tmp=hand;
    int ma=-1<<30,mi=1<<30,value,v[10];
    if (hand.empty())
    {
        hand=now;
        value=dfs(dep+1,!red);
        ma=max(ma,value);
        mi=min(mi,value);
        hand.clear();
    }
    for (int i=0;i<=s1[0];i++)
        v[i]=s1[i];
    for (int k=1;k<=v[0];k++)
    {
        int i=v[k]/100,j=v[k]%100;
        del(s1,i*100+j);
        s2[++s2[0]]=(i+1)*100+2*j-1;
        if (!hand.empty())
        {
            a[i][j]=hand;
            hand=now;
            value=get(a[i][j],a[i-1][2*j],a[i-1][2*j+1])+dfs(dep+1,!red);
            ma=max(ma,value);
            mi=min(mi,value);
            hand=tmp;
        }
        a[i][j]=now;
        value=get(a[i][j],a[i-1][2*j],a[i-1][2*j+1])+dfs(dep+1,!red);
        ma=max(ma,value);
        mi=min(mi,value);
        a[i][j].clear();
        s1[++s1[0]]=i*100+j;
        del(s2,(i+1)*100+2*j-1);
    }
    if (!hand.empty())
    {
        for (int i=0;i<=s2[0];i++)
            v[i]=s2[i];
        hand.clear();
        for (int k=1;k<=v[0];k++)
        {
            int i=v[k]/100,j=v[k]%100;
            del(s2,i*100+j);
            if (!a[i][j-1].empty())
                s1[++s1[0]]=(i+1)*100+(j-1)/2;
            if (!a[i][j+2].empty())
                s1[++s1[0]]=(i+1)*100+(j+1)/2;
            a[i][j]=tmp;
            a[i][j+1]=now;
            value=get(a[i][j],a[i][j+1],a[i-1][(j+1)/2])+dfs(dep+1,!red);
            ma=max(ma,value);
            mi=min(mi,value);
            a[i][j]=now;
            a[i][j+1]=tmp;
            value=get(a[i][j],a[i][j+1],a[i-1][(j+1)/2])+dfs(dep+1,!red);
            ma=max(ma,value);
            mi=min(mi,value);
            a[i][j].clear();
            a[i][j+1].clear();
            s2[++s2[0]]=i*100+j;
            if (!a[i][j-1].empty())
                del(s1,(i+1)*100+(j-1)/2);
            if (!a[i][j+2].empty())
                del(s1,(i+1)*100+(j+1)/2);
        }
        hand=tmp;
    }
    return(red?ma:mi);
}
int main()
{

    while (1)
    {
        scanf("%s",player);
        if (player[0]=='E')
            break;
        scanf("%d",&n);
        n<<=1;
        for (int i=1;i<=n;i++)
            deck[i].in();
        hr.clear();
        hb.clear();
        for (int i=1;i<=7;i++)
            for (int j=0;j<10;j++)
                a[i][j].clear();
        s1[0]=3;
        for (int i=1;i<=3;i++)
            s1[i]=200+i;
        s2[0]=0;
        for (int i=1;i<=8;i++)
            a[1][i]=deck[i];
        int ans=deck[1].suit=='R'?dfs(9,true):dfs(9,false);
        static int id=0;
        printf("Case %d: ",++id);
        if (ans==0)
            printf("Axel and Birgit tie\n");
        else
        {
            if (player[0]=='B')
                ans=-ans;
            printf("%s ",player);
            if (ans>0)
                printf("wins %d\n",ans);
            else
                printf("loses %d\n",-ans);
        }
    }
    return(0);
}

