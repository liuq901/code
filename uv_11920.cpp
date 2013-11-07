#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector <string> a;
char s[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        a.clear();
        int len=strlen(s);
        string now;
        now=s[0];
        for (int i=1;i<len;i++)
            if (s[i]==s[i-1])
                now+=s[i];
            else
            {
                a.push_back(now);
                now=s[i];
            }
        a.push_back(now);
        int ans=0;
        for (int i=0;i<a.size();i++)
        {
            if (a[i][0]!='?')
            {
                ans=max(ans,int(a[i].size()));
                continue;
            }
            int l,r;
            l=r=-1;
            if (i>0)
                l='1'-a[i-1][0];
            if (i<a.size()-1)
                r='1'-a[i+1][0];
            if (a[i].size()>1)
            {
                int value=1;
                if (l!=-1 && r!=-1 && a[i].size()%2-(l==r)!=0)
                    value=2;
                ans=max(ans,value);
                continue;
            }
            if (l!=-1 && r!=-1 && l!=r)
                if (a[i-1].size()<=a[i+1].size())
                    ans=max(ans,int(a[i-1].size()+1));
                else
                    a[i+1]+=a[i+1][0];
            else
                ans=max(ans,1);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

