#include <cstdio>
#include <string>
#include <queue>
using namespace std;
int a[100010];
string name[100010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    queue <int> Q;
    for (int i=1;i<=n;i++)
    {
        char buf[20];
        scanf("%s%d",buf,&a[i]);
        name[i]=buf;
        Q.push(i);
    }
    int now=0;
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        if (a[x]<=m)
        {
            now+=a[x];
            printf("%s %d\n",name[x].c_str(),now);
        }
        else
        {
            now+=m;
            a[x]-=m;
            Q.push(x);
        }
    }
    return(0);
}

