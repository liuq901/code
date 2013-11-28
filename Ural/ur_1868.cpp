#include <cstdio>
#include <string>
#include <set>
#include <map>
using namespace std;
set <string> medal[3];
map <string,int> M;
int ans[110];
char s[100000],t[100000];
int main()
{
    M["gold"]=0,M["silver"]=1,M["bronze"]=2;
    for (int i=0;i<3;i++)
        for (int j=1;j<=4;j++)
        {
            scanf("%s",s);
            medal[i].insert(s);
        }
    int n,tot=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int m;
        scanf("%d",&m);
        for (int j=1;j<=m;j++)
        {
            scanf("%s : %s",s,t);
            ans[i]+=medal[M[t]].count(s);
        }
        tot=max(tot,ans[i]);
    }
    int sum=0;
    for (int i=1;i<=n;i++)
        sum+=tot==ans[i];
    printf("%d\n",sum*5);
    return(0);
}

