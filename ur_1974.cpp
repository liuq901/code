#include <cstdio>
#include <string>
#include <utility>
#include <map>
#include <algorithm>
#define hash hahaha
using namespace std;
map <string,string> to;
map <pair <int,string>,int > M;
int a[1010],b[1010];
void init()
{
    to["C+"]="D-";
    to["D+"]="E-";
    to["E"]="F-";
    to["F"]="E+";
    to["F+"]="G-";
    to["G+"]="A-";
    to["A+"]="B-";
}
pair <int,string> get(int x,string s)
{
    if (s=="B+")
        return(make_pair(x+1,"C"));
    if (s=="C-")
        return(make_pair(x-1,"B"));
    if (to.count(s))
        return(make_pair(x,to[s]));
    return(make_pair(x,s));
}
int hash(const pair <int,string> &x)
{
    if (!M.count(x))
    {
        int id=M.size()+1;
        M[x]=id;
    }
    return(M[x]);
}
int calc(int n,int m)
{
    int ans=0;
    for (int i=-m;i<=n;i++)
    {
        int now=0;
        for (int j=1;j<=m;j++)
        {
            int id=i+j-1;
            if (id<=0)
                continue;
            if (id>n)
                break;
            now+=a[id]==b[j];
            ans=max(ans,now);
        }
    }
    return(ans);
}
int main()
{
    init();
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        char buf[10];
        scanf("%d%s",&x,buf);
        a[i]=hash(get(x,buf));
    }
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int m;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
        {
            int x;
            char buf[10];
            scanf("%d%s",&x,buf);
            b[i]=hash(get(x,buf));
        }
        printf("%.10f\n",calc(n,m)/double(m));
    }
    return(0);
}

