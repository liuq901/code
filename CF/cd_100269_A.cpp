#include <cstdio>
char buf[1000000];
int cnt[26];
int main()
{
    freopen("arrange.in","r",stdin);
    freopen("arrange.out","w",stdout);
    int n,ans=26;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",buf);
        cnt[buf[0]-'A']++;
    }
    for (int i=0;i<26;i++)
        if (cnt[i]==0)
        {
            ans=i;
            break;
        }
    printf("%d\n",ans);
    return(0);
}

