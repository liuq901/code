#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char s[3010],t[3010],*p[3010];
vector <int> a[3010];
int q[3010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",s,t);
        int n=strlen(s),m=strlen(t);
        bool first=t[0]=='*',last=t[m-1]=='*';
        for (int i=0;i<m;i++)
            if (t[i]=='*')
                t[i]='\0';
        int num=0;
        for (int i=0;i<m;i++)
            if (t[i])
            {
                p[num++]=t+i;
                i+=strlen(t+i);
            }
        static int id=0;
        if (!num)
        {
            printf("Case %d: %d\n",++id,n*(n+1)/2);
            continue;
        }
        for (int i=0;i<num;i++)
        {
            a[i].clear();
            q[i]=strlen(p[i]);
            int len=q[i];
            for (int j=0;j+len<=n;j++)
            {
                bool find=false;
                for (int k=0;k<len;k++)
                    if (p[i][k]!='?' && s[j+k]!=p[i][k])
                    {
                        find=true;
                        break;
                    }
                if (!find)
                    a[i].push_back(j);
            }
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            int pos=lower_bound(a[0].begin(),a[0].end(),i)-a[0].begin();
            if (pos==a[0].size())
                continue;
            pos=a[0][pos];
            if (!first && pos!=i)
                continue;
            for (int j=1;j<num;j++)
            {
                pos+=q[j-1];
                pos=lower_bound(a[j].begin(),a[j].end(),pos)-a[j].begin();
                if (pos==a[j].size())
                {
                    pos=-1;
                    break;
                }
                else
                    pos=a[j][pos];
            }
            if (pos==-1)
                continue;
            if (last)
            {
                pos+=q[num-1];
                ans+=n-pos+1;
            }
            else if (num>=2)
            {
                pos=lower_bound(a[num-1].begin(),a[num-1].end(),pos)-a[num-1].begin();
                ans+=a[num-1].size()-pos;
            }
            else
                ans++;
        }
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

