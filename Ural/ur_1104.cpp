#include <cstdio>
#include <cstring>
#include <cctype>
char s[1000010];
int main()
{
    scanf("%s",s);
    int n=strlen(s),ans=-1;
    for (int i=2;i<=36;i++)
    {
        int sum=0;
        for (int j=0;j<n;j++)
        {
            int x=isdigit(s[j])?s[j]-'0':s[j]-'A'+10;
            if (x>=i)
            {
                sum=-1;
                break;
            }
            sum=(sum*i+x)%(i-1);
        }
        if (sum==0)
        {
            ans=i;
            break;
        }
    }
    if (ans==-1)
        printf("No solution.\n");
    else
        printf("%d\n",ans);
    return(0);
}

