#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
struct card
{
    int num;
    char suit;
    card(){}
    card(const char *s)
    {
        suit=s[1];
        if (isdigit(s[0]))
            num=s[0]-'0';
        else if (s[0]=='T')
            num=10;
        else if (s[0]=='J')
            num=11;
        else if (s[0]=='Q')
            num=12;
        else if (s[0]=='K')
            num=13;
        else
            num=14;
    }
};
struct hand
{
    int kind;
    vector <int> value;
};
inline bool operator <(const card &a,const card &b)
{
    return(a.num>b.num);
}
inline bool operator >(const hand &a,const hand &b)
{
    if (a.kind!=b.kind)
        return(a.kind<b.kind);
    for (int i=0;i<a.value.size();i++)
        if (a.value[i]!=b.value[i])
            return(a.value[i]>b.value[i]);
    return(false);
}
card a[10],b[10];
bool flush(card *a)
{
    for (int i=1;i<=5;i++)
        if (a[i].suit!=a[1].suit)
            return(false);
    return(true);
}
bool straight(card *a)
{
    for (int i=2;i<=5;i++)
        if (a[i].num!=a[i-1].num-1)
            return(false);
    return(true);
}
hand get(card *a)
{
    hand ret;
    sort(a+1,a+6);
    int c[20]={0},d[10]={0};
    for (int i=1;i<=5;i++)
        c[a[i].num]++;
    for (int i=2;i<=14;i++)
    {
        if (c[i]<=1)
            continue;
        if (c[i]>2)
            d[c[i]]=i;
        else if (d[2]==0)
            d[2]=i;
        else
            d[1]=i;
    }
    if (flush(a) && straight(a) && a[1].num==10)
        ret.kind=1;
    else if (flush(a) && straight(a))
    {
        ret.value.push_back(a[1].num);
        ret.kind=2;
    }
    else if (d[4]!=0)
    {
        ret.value.push_back(d[4]);
        for (int i=1;i<=5;i++)
            if (a[i].num!=d[4])
                ret.value.push_back(a[i].num);
        ret.kind=3;
    }
    else if (d[3]!=0 && d[2]!=0)
    {
        ret.value.push_back(d[3]);
        ret.value.push_back(d[2]);
        ret.kind=4;
    }
    else if (flush(a))
    {
        for (int i=1;i<=5;i++)
            ret.value.push_back(a[i].num);
        ret.kind=5;
    }
    else if (straight(a))
    {
        ret.value.push_back(a[1].num);
        ret.kind=6;
    }
    else if (d[3]!=0)
    {
        ret.value.push_back(d[3]);
        for (int i=1;i<=5;i++)
            if (a[i].num!=d[3])
                ret.value.push_back(a[i].num);
        ret.kind=7;
    }
    else if (d[2]!=0 && d[1]!=0)
    {
        ret.value.push_back(max(d[1],d[2]));
        ret.value.push_back(min(d[1],d[2]));
        for (int i=1;i<=5;i++)
            if (a[i].num!=d[1] && a[i].num!=d[2])
                ret.value.push_back(a[i].num);
        ret.kind=8;
    }
    else if (d[2]!=0)
    {
        ret.value.push_back(d[2]);
        for (int i=1;i<=5;i++)
            if (a[i].num!=d[2])
                ret.value.push_back(a[i].num);
        ret.kind=9;
    }
    else
    {
        for (int i=1;i<=5;i++)
            ret.value.push_back(a[i].num);
        ret.kind=10;
    }
    return(ret);
}
int main()
{
    int ans=0;
    for (int i=1;i<=1000;i++)
    {
        char buf[10];
        for (int j=1;j<=5;j++)
        {
            scanf("%s",buf);
            a[j]=buf;
        }
        for (int j=1;j<=5;j++)
        {
            scanf("%s",buf);
            b[j]=buf;
        }
        hand x=get(a),y=get(b);
        ans+=x>y;
    }
    printf("%d\n",ans);
    return(0);
}

