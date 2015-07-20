#include <cstdio>
char s[210];
int main()
{
    int n,a[3];
    scanf("%d%d%d%s",&n,&a[0],&a[1],s);
    if (a[0]+a[1]>n)
        printf("-1\n");
    else
    {
        a[2]=n-a[0]-a[1];
        int ans=0;
        for (int i=0;i<n;i++)
        {
            int x=s[i]-'0';
            if (a[x]==0)
            {
                ans++;
                s[i]='?';
            }
            else
                a[x]--;
        }
        int t=0;
        for (int i=0;i<n;i++)
        {
            if (s[i]!='?')
                continue;
            while (a[t]==0)
                t++;
            a[t]--;
            s[i]=t+'0';
        }
        printf("%d\n%s\n",ans,s);
    }
    return(0);
}

