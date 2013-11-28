#include <cstdio>
#include <cstring>
const int mod=1000000007;
int a[30];
char s[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s+1);
        int len=strlen(s+1);
        memset(a,0,sizeof(a));
        a[26]=1;
        for (int i=1;i<=len;i++)
        {
            int now=0;
            for (int j=0;j<=26;j++)
                now=(now+a[j])%mod;
            a[s[i]-'A']=now;
        }
        int ans=0;
        for (int i=0;i<=26;i++)
            ans=(ans+a[i])%mod;
        printf("%d\n",ans);
    }
    return(0);
}

