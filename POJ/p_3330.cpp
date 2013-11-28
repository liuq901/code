#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef pair <ull,ull> Hash;
const int lq=1351,LQ=7123,lQ=123451,Lq=10007;
const double eps=1e-8;
double sim[200];
string s;
int tot,l[200],r[200],d[200];
vector <Hash> a[200];
int build(int begin,int end)
{
    int id=++tot;
    d[id]=1;
    if (begin!=end)
    {
        int sum=0,k;
        for (int i=begin+1;i<end;i++)
        {
            if (s[i]=='(')
                sum++;
            if (s[i]==')')
                sum--;
            if (s[i]==' ' && sum==0)
            {
                k=i;
                break;
            }
        }
        l[id]=build(begin+1,k-1);
        r[id]=build(k+1,end-1);
        d[id]+=d[l[id]]+d[r[id]];
    }
    else
        l[id]=r[id]=0;
    return(id);
}
Hash hash(int x)
{
    a[x].clear();
    if (!l[x])
    {
        a[x].push_back(make_pair(1,26));
        return(make_pair(1,26));
    }
    Hash left=hash(l[x]),right=hash(r[x]);
    int ll=d[l[x]],rr=d[r[x]];
    if (left>right)
    {
        swap(left,right);
        swap(ll,rr);
    }
    Hash now=make_pair((left.first*lq+right.first*LQ)*ll,(left.second*Lq+right.second*lQ)*rr);
    a[x].push_back(now);
    for (int i=0;i<a[l[x]].size();i++)
        a[x].push_back(a[l[x]][i]);
    for (int i=0;i<a[r[x]].size();i++)
        a[x].push_back(a[r[x]][i]);
    sort(a[x].begin(),a[x].end());
    a[x].erase(unique(a[x].begin(),a[x].end()),a[x].end());
    return(now);
}
void calc(int x)
{
    if (!l[x])
    {
        sim[x]=0;
        return;
    }
    int sum=a[x].size()-1;
    sim[x]=double(a[l[x]].size()+a[r[x]].size()-sum)/sum;
    calc(l[x]);
    calc(r[x]);
}
int strong(int x,int y)
{
    if (fabs(sim[x]-sim[y])<eps)
    {
        if (!l[x])
            return(0);
        int x1=l[x],y1=r[x],x2=l[y],y2=r[y];
        if (strong(x1,y1)==-1)
            swap(x1,y1);
        if (strong(x2,y2)==-1)
            swap(x2,y2);
        int p=strong(x1,x2);
        if (p==0)
            return(strong(y1,y2));
        return(p);
    }
    return(sim[x]<sim[y]?1:-1);
}
void change(int x,bool isleft)
{
    if (!l[x])
        return;
    int p,q;
    if (strong(l[x],r[x])>=0)
        p=l[x],q=r[x];
    else
        p=r[x],q=l[x];
    if (isleft)
        l[x]=p,r[x]=q;
    else
        l[x]=q,r[x]=p;
    change(l[x],true);
    change(r[x],false);
}
void print(int x)
{
    if (!l[x])
    {
        printf("x");
        return;
    }
    printf("(");
    print(l[x]);
    printf(" ");
    print(r[x]);
    printf(")");
}
int main()
{
    while (1)
    {
        getline(cin,s);
        if (s[0]=='0')
            break;
        tot=0;
        build(0,s.size()-1);
        hash(1);
        calc(1);
        change(1,true);
        print(1);
        printf("\n");
    }
    return(0);
}

