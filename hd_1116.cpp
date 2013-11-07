#include <cstdio>
#include <cstring>
int a[260],b[260],f[260];
char s[100000];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (char c='a';c<='z';c++)
            f[c]=c;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s);
            int len=strlen(s);
            a[s[0]]++;
            b[s[len-1]]++;
            f[find(s[0])]=find(s[len-1]);
        }
        char k=' ';
        bool flag=true;
        for (char c='a';c<='z';c++)
        {
            if (a[c]==0 && b[c]==0)
                continue;
            if (k==' ')
                k=c;
            else if (find(k)!=find(c))
            {
                flag=false;
                break;
            }
        }
        int s1,s2;
        s1=s2=0;
        for (char c='a';c<='z';c++)
            if (a[c]>=b[c])
                s1+=a[c]-b[c];
            else
                s2+=b[c]-a[c];
        printf("%s\n",s1<=1 && s2<=1 && flag?"Ordering is possible.":"The door cannot be opened.");
    }
    return(0);
}

