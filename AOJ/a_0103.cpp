#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int ans,out;
        bool a,b,c,d;
        char s[10];
        ans=out=0;
        a=b=c=d=false;
        while (out<3)
        {
            scanf("%s",s);
            if (s[0]=='H' && s[1]=='I')
            {
                d=c,c=b,b=a,a=true;
                if (d)
                {
                    ans++;
                    d=false;
                }
            }
            else if (s[0]=='H')
            {
                ans+=a+b+c+d+1;
                a=b=c=d=false;
            }
            else
                out++;
        }
        printf("%d\n",ans);
    }
    return(0);
}

