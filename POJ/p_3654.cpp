#include <cstdio>
#include <cstring>
#include <cctype>
int a[30];
bool f[30];
char s[100];
void work(int l,int r)
{
    int k;
    for (int i=l;i<=r;i++)
        if (!isalpha(s[i]))
        {
            k=i;
            break;
        }
    int now=0;
    for (int i=k+1;i<=r;i++)
        now|=1<<s[i]-'a';
    for (int i=l;i<k;i++)
    {
        int x=s[i]-'A'+1;
        if (s[k]=='=')
            a[x]=now;
        else if (s[k]=='+')
            a[x]|=now;
        else if (s[k]=='-')
            a[x]&=~now;
    }
}
int main()
{
    while (1)
    {
        scanf("%s",s);
        if (s[0]=='#')
            break;
        int n=strlen(s);
        s[n]=',';
        memset(a,0,sizeof(a));
        int left=0;
        for (int i=0;i<=n;i++)
            if (s[i]==',')
            {
                work(left,i-1);
                left=i+1;
            }
        static int id=0;
        printf("%d:",++id);
        int pre=0;
        memset(f,0,sizeof(f));
        for (int i=1;i<=26;i++)
        {
            if (a[i]==0)
                continue;
            if (a[i]==a[pre])
                f[pre]=true;
            pre=i;
        }
        for (int i=1;i<=26;i++)
        {
            if (a[i]==0)
                continue;
            printf("%c",i+'A'-1);
            if (!f[i])
                for (int j=0;j<26;j++)
                    if (a[i]>>j&1)
                        printf("%c",j+'a');
        }
        printf("\n");
    }
    return(0);
}

