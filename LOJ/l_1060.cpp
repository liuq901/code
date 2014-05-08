#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
int n,cnt[26];
char s[30];
ll f[30];
void init()
{
    f[0]=1;
    for (int i=1;i<=20;i++)
        f[i]=f[i-1]*i;
}
string dfs(int dep,ll num)
{
    if (dep==n)
        return("");
    for (int i=0;i<26;i++)
    {
        if (cnt[i]==0)
            continue;
        cnt[i]--;
        ll now=f[n-dep-1];
        for (int j=0;j<26;j++)
            now/=f[cnt[j]];
        if (num<=now)
            return(char('a'+i)+dfs(dep+1,num));
        num-=now;
        cnt[i]++;
    }
    return("Impossible");
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll num;
        scanf("%s%lld",s,&num);
        n=strlen(s);
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<n;i++)
            cnt[s[i]-'a']++;
        static int id=0;
        printf("Case %d: %s\n",++id,dfs(0,num).c_str());
    }
    return(0);
}

