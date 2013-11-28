#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int c[]={1,4,9,16,25,36,49,64,81};
vector <vector <int> > a;
vector <int> now;
void dfs(int first,int dep)
{
    if (dep==6)
    {
        a.push_back(now);
        return;
    }
    for (int i=first;i<10;i++)
    {
        now.push_back(i);
        dfs(i+1,dep+1);
        now.pop_back();
    }
}
bool in(const vector <int> &a,int x)
{
    for (int i=0;i<a.size();i++)
    {
        if (a[i]==6 && x==9 || a[i]==9 && x==6 || a[i]==x)
            return(true);
    }
    return(false);
}
bool check(const vector <int> &a,const vector <int> &b)
{
    for (int i=0;i<9;i++)
    {
        int x=c[i]/10,y=c[i]%10;
        if (!(in(a,x) && in(b,y)) && !(in(a,y) && in(b,x)))
            return(false);
    }
    return(true);
}
int main()
{
    dfs(0,0);
    int ans=0;
    for (int i=0;i<a.size();i++)
        for (int j=i+1;j<a.size();j++)
            ans+=check(a[i],a[j]);
    printf("%d\n",ans);
    return(0);
}

