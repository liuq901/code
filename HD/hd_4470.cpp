#include <cstdio>
#include <cctype>
#include <utility>
#include <algorithm>
using namespace std;
inline bool bust(const pair <int,int> &a)
{
    return(a.first>21);
}
inline bool all(const pair <int,int> &a)
{
    return(a.second==5 && !bust(a));
}
inline bool hit(const pair <int,int> &a)
{
    if (bust(a) || all(a))
        return(false);
    return(a.first<=15);
}
inline void update(pair <int,int> &a,int b)
{
    a.first+=b;
    a.second++;
}
inline bool beat(const pair <int,int> &a,const pair <int,int> &b)
{
    if (bust(a) || all(b))
        return(false);
    if (all(a) || bust(b))
        return(true);
    return(a.first>b.first);
}
inline int to(int &now,int p,int q)
{
    int ret=now;
    if (now==q)
        now=1;
    else if (now==p-1)
        now=q+1;
    else
        now++;
    return(ret);
}
int a[2010];
pair <int,int> f[2010][2010];
int play(int &now,int p,int q)
{
    pair <int,int> alice(0,0),bob(0,0);
    update(alice,a[to(now,p,q)]);
    update(bob,a[to(now,p,q)]);
    update(alice,a[to(now,p,q)]);
    update(bob,a[to(now,p,q)]);
    while (hit(alice))
        update(alice,a[to(now,p,q)]);
    while (!bust(alice) && !all(alice) && hit(bob))
        update(bob,a[to(now,p,q)]);
    return(beat(alice,bob));
}
int calc(int p,int q,int n,int K)
{
    int num2=p-1,num3=n-q,ret;
    if (num2+num3<K)
    {
        int delta=K-num2-num3;
        ret=f[p][q-delta].first;
        int now=f[p][q-delta].second;
        while (now>=p && now<=q-delta)
            ret+=play(now,p,q);
    }
    else if (num3<K)
    {
        int delta=K-num3;
        ret=f[p][q].first;
        int now=f[p][q].second;
        if (now==q+1)
            now=1;
        while (now>=p && now<=q)
            ret+=play(now,p,q);
        if (now>=1 && now<=p-1-delta)
        {
            ret+=f[now][p-1-delta].first;
            now=f[now][p-1-delta].second;
            while (now>=1 && now<=p-1-delta)
                ret+=play(now,p,q);
        }
    }
    else
    {
        int delta=K;
        ret=f[p][q].first;
        int now=f[p][q].second;
        if (now==q+1)
            now=1;
        while (now>=p && now<=q)
            ret+=play(now,p,q);
        if (now>=1 && now<=p-1)
        {
            ret+=f[now][p-1].first;
            now=f[now][p-1].second;
            if (now==p)
                now=q+1;
            while (now>=1 && now<=p-1)
                ret+=play(now,p,q);
        }
        if (now>=q+1 && now<=n-delta)
        {
            ret+=f[now][n-delta].first;
            now=f[now][n-delta].second;
            while (now>=q+1 && now<=n-delta)
                ret+=play(now,p,q);
        }
    }
    return(ret);
}
int main()
{
    int n,K;
    while (scanf("%d%d",&n,&K)==2)
    {
        K--;
        for (int i=1;i<=n;i++)
        {
            char s[10];
            scanf("%s",s);
            if (s[0]=='A')
                a[i]=1;
            else if (isalpha(s[0]))
                a[i]=10;
            else
                a[i]=s[0]-'0';
        }
        for (int i=n;i;i--)
        {
            int win,rest;
            if (i+3>n)
                rest=-1;
            else
            {
                int now=i;
                pair <int,int> alice(0,0),bob(0,0);
                update(alice,a[now++]);
                update(bob,a[now++]);
                update(alice,a[now++]);
                update(bob,a[now++]);
                bool flag=true;
                while (hit(alice))
                {
                    if (now>n)
                    {
                        flag=false;
                        break;
                    }
                    update(alice,a[now++]);
                }
                while (!bust(alice) && !all(alice) && hit(bob))
                {
                    if (now>n)
                    {
                        flag=false;
                        break;
                    }
                    update(bob,a[now++]);
                }
                if (!flag)
                    rest=-1;
                else
                {
                    win=beat(alice,bob);
                    rest=now;
                }
            }
            if (rest==-1)
                for (int j=i;j<=n;j++)
                    f[i][j]=make_pair(0,i);
            else
            {
                for (int j=i;j<rest-1;j++)
                    f[i][j]=make_pair(0,i);
                f[i][rest-1]=make_pair(win,rest);
                for (int j=rest;j<=n;j++)
                    f[i][j]=make_pair(f[rest][j].first+win,f[rest][j].second);
            }
        }
        int ans=0;
        for (int i=2;i<n;i++)
            for (int j=i;j<n;j++)
                ans=max(ans,calc(i,j,n,K));
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

