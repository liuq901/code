#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
double F[100][1100];
int kind[100],speed[100],power[100];
double kick(int round)
{
    double p=1;
    for (int i=1;i<=round;i++)
        p*=2.0/3.0;
    return(1-p);
}
vector <pair <int,double> > meet(int i,int j)
{
    vector <pair <int,double> > ret;
    if (kind[i]==0)
    {
        double p=1.0/3.0*kick(3);
        ret.push_back(make_pair(-1,p));
        ret.push_back(make_pair(0,1-p));
        return(ret);
    }
    if (kind[i]==1)
    {
        if (kind[j]==0)
            ret.push_back(make_pair(0,1.0));
        else
        {
            double p=kick(power[i]-(kind[j]==2?power[j]:0));
            ret.push_back(make_pair(1,p));
            ret.push_back(make_pair(0,1-p));
        }
        return(ret);
    }
    if (kind[i]==2)
    {
        if (kind[j]==3)
        {
            double p=kick(power[i]-power[j]);
            ret.push_back(make_pair(1,p));
            ret.push_back(make_pair(0,1-p));
        }
        else
            ret.push_back(make_pair(0,1.0));
        return(ret);
    }
    if (kind[i]==3)
    {
        if (kind[j]==0)
            ret.push_back(make_pair(0,1.0));
        else
            ret.push_back(make_pair(max(0,power[i]-(kind[j]==2?power[j]:0)),1.0));
        return(ret);
    }
}
double getRate(int mask,int win,int alice,int bob)
{
    double dp(int,int);
    vector <pair <int,double> > u,v;
    u=meet(alice,bob);
    v=meet(bob,alice);
    double ret=0;
    for (int i=0;i<u.size();i++)
        for (int j=0;j<v.size();j++)
            ret+=dp(win+u[i].first-v[j].first,mask^1<<alice^1<<bob)*u[i].second*v[j].second;
    return(ret);
}
double calc(int win,int mask,int alice,int bob)
{
    double ret;
    if (speed[alice]>=speed[bob])
    {
        ret=-1;
        for (int i=5;i<=8;i++)
            if (mask>>i&1)
                ret=max(ret,getRate(mask,win,alice,i));
    }
    else
    {
        ret=10;
        for (int i=0;i<=3;i++)
            if (mask>>i&1)
                ret=min(ret,getRate(mask,win,i,bob));
    }
    return(ret);
}
double choose(int win,int mask,int alice)
{
    int ma=-1;
    for (int i=5;i<=8;i++)
        if (mask>>i&1)
            ma=max(ma,speed[i]);
    double ret=10;
    for (int i=5;i<=8;i++)
        if (mask>>i&1 && speed[i]==ma)
            ret=min(ret,calc(win,mask,alice,i));
    return(ret);
}
inline double &f(int win,int mask)
{
    return(F[win+45][mask]);
}
double dp(int win,int mask)
{
    if (mask==0)
    {
        if (win==0)
            return(0.5);
        return(win>0);
    }
    if (mask==528)
    {
        if (win!=0)
            return(win>0);
        return(getRate(528,win,4,9));
    }
    if (f(win,mask)>-1)
        return(f(win,mask));
    int ma=-1;
    for (int i=0;i<=3;i++)
        if (mask>>i&1)
            ma=max(ma,speed[i]);
    double &ret=f(win,mask);
    for (int i=0;i<=3;i++)
        if (mask>>i&1 && speed[i]==ma)
            ret=max(ret,choose(win,mask,i));
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=0;i<10;i++)
            scanf("%d%d%d",&kind[i],&speed[i],&power[i]);
        for (int i=0;i<100;i++)
            for (int j=0;j<1<<10;j++)
                F[i][j]=-10;
        printf("%.0f\n",dp(0,1023)*100);
    }
    return(0);
}

