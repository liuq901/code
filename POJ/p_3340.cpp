#include <cstdio>
#include <cstring>
typedef long long ll;
char a[20],b[20];
int main()
{
    while (scanf("%s%s",a,b)==2)
    {
        int n=strlen(a);
        ll x=0,y=1;
        for (int i=0;i<n;i++)
            if (a[i]=='?')
                x=x*10+y*(9-(b[i]-'0'));
            else
            {
                x+=y*(a[i]>b[i]);
                y*=a[i]==b[i];
            }
        printf("%I64d\n",x);
    }
    return(0);
}

