#include <cstdio>
#include <cstring>
#include <cctype>
char s[100000];
int a[30];
int calc(int x,int d)
{
    x=(x-d)%26;
    if (x<0)
        x+=26;
    return(x);
}
int main()
{
    int T;
    scanf("%d",&T);
    gets(s);
    while (T--)
    {
        gets(s);
        int len=strlen(s);
        memset(a,0,sizeof(a));
        for (int i=0;i<len;i++)
            if (isalpha(s[i]))
                a[s[i]-'A']++;
        int ans=0,k=-1;
        for (int i=0;i<26;i++)
            if (a[i]>ans)
                ans=a[i];
        for (int i=0;i<26;i++)
        {
            if (a[i]!=ans)
                continue;
            if (k!=-1)
            {
                ans=-1;
                break;
            }
            k=i;
        }
        if (ans==-1)
            printf("NOT POSSIBLE\n");
        else
        {
            k=calc(k,4);
            printf("%d ",k);
            for (int i=0;i<len;i++)
                if (isalpha(s[i]))
                    printf("%c",calc(s[i]-'A',k)+'A');
                else
                    printf("%c",s[i]);
            printf("\n");
        }
    }
    return(0);
}

