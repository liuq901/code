#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
string s[10000];
bool vis[10000];
char buf[100000];
int main()
{
    while (1)
    {
        scanf("%s",buf);
        string S=buf;
        if (S=="0")
            break;
        int n;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for (int i=0;i<n;i++)
        {
            scanf("%s",buf);
            s[i]=buf;
            vis[i]=true;
        }
        int cnt=1+(n>10),last=-1,N=n;
        string ans;
        for (int i=0;i<S.size();)
        {
            int now=atoi(S.substr(i,cnt).c_str());
            if (!vis[now])
            {
                s[now]=s[last]+s[last][0];
                vis[now]=true;
                last=-1;
            }
            string tmp=s[now];
            ans+=tmp;
            if (N==1)
            {
                string add=tmp+s[0][0];
                s[n]=add;
                vis[n]=true;
            }
            else
            {
                if (last!=-1)
                {
                    string add=s[last]+tmp[0];
                    s[n-1]=add;
                    vis[n-1]=true;
                }
                last=now;
            }
            i+=cnt;
            n++;
            if (n>10)
                cnt=2;
            if (n>100)
                cnt=3;
            if (n>1000)
                cnt=4;
        }
        static int id=0;
        printf("Case %d: %s\n",++id,ans.c_str());
    }
    return(0);
}

