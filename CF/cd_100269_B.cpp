#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[20];
char buf[1000000];
string s[20];
int main()
{
    freopen("bad.in","r",stdin);
    freopen("bad.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",buf);
        s[i]=buf;
        a[i]=make_pair(0,i);
    }
    int tot=0;
    for (int i=1;i<=m;i++)
    {
        scanf("%s",buf+1);
        int cnt=0,pos;
        for (int j=1;j<=n;j++)
            if (buf[j]=='X')
            {
                cnt++;
                pos=j;
            }
        if (cnt==1)
            a[pos].first--;
        else
            tot++;
    }
    sort(a+1,a+n+1);
    s[n+1]="Invalid";
    a[n+1]=make_pair(-tot,n+1);
    for (int i=1;i<=n+1;i++)
    {
        int id=a[i].second;
        double p=a[i].first==0?0:-100.0*a[i].first/m;
        printf("%s %.2f%%\n",s[id].c_str(),p);
    }
    return(0);
}

