#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
map <char,pair <int,int> > a;
char s[100000];
int main()
{
    a['A']=make_pair(1,2);
    for (int i='B';i<='Z';i++)
    {
        int x=a[i-1].first,y=a[i-1].second;
        if (i=='D' || i=='G' || i=='J' || i=='M' || i=='P' || i=='T' || i=='W')
            a[i]=make_pair(1,y+1);
        else
            a[i]=make_pair(x+1,y);
    }
    a[' ']=make_pair(1,1);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int p,w;
        scanf("%d%d",&p,&w);
        gets(s);
        gets(s);
        int n=strlen(s),ans=0;
        for (int i=0;i<n;i++)
        {
            ans+=a[s[i]].first*p;
            if (i!=0 && s[i]!=' ' && a[s[i]].second==a[s[i-1]].second)
                ans+=w;
        }
        printf("%d\n",ans);
    }
    return(0);
}

