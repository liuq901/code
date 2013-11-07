#include <cstdio>
#include <cstring>
#include <utility>
#include <set>
using namespace std;
bool have[20][10];
set <pair <int,int> > a,b;
pair <int,int> card(char *s)
{
    pair <int,int> ret;
    if (s[0]=='T')
        ret.first=10;
    else if (s[0]=='J')
        ret.first=11;
    else if (s[0]=='Q')
        ret.first=12;
    else if (s[0]=='K')
        ret.first=13;
    else if (s[0]=='A')
        ret.first=14;
    else
        ret.first=s[0]-'0';
    if (s[1]=='D')
        ret.second=1;
    else if (s[1]=='C')
        ret.second=2;
    else if (s[1]=='H')
        ret.second=3;
    else
        ret.second=4;
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(have,0,sizeof(have));
        a.clear();
        b.clear();
        for (int i=1;i<=26;i++)
        {
            char buf[10];
            scanf("%s",buf);
            pair <int,int> tmp=card(buf);
            have[tmp.first][tmp.second]=true;
            a.insert(tmp);
        }
        for (int i=2;i<=14;i++)
            for (int j=1;j<=4;j++)
                if (!have[i][j])
                    b.insert(make_pair(i,j));
        int ans=0;
        for (set <pair <int,int> >::iterator k=b.begin();k!=b.end();k++)
        {
            pair <int,int> now=*k;
            set <pair <int,int> >::iterator t=a.upper_bound(now);
            if (t==a.end())
                a.erase(a.begin());
            else
            {
                ans++;
                a.erase(t);
            }
        }
        printf("%d\n",ans);
    }
    return(0);
}

