#include <cstdio>
char s[100];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        scanf("%s",s);
        int R=0,Y=0;
        bool flag;
        for (int i=0;i<n;i++)
        {
            R+=s[i]=='R';
            Y+=s[i]=='Y';
        }
        if (s[n-1]=='B')
            printf("%s\n",R==7?"Red":"Yellow");
        else
            printf("%s\n",Y==7?"Yellow":"Red");
    }
    return(0);
}

