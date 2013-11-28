#include <cstdio>
#include <string>
using namespace std;
string now;
int n,ans=0;
void dfs(int dep)
{
    if (dep==n)
    {
        ans+=now.find("010")==string::npos;
        return;
    }
    now[dep]='0';
    dfs(dep+1);
    now[dep]='1';
    dfs(dep+1);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==-1)
            break;
        now.resize(n);
        ans=0;
        dfs(0);
        printf("%d\n",ans);
    }
    return(0);
}

