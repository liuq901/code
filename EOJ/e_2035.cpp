#include <cstdio>
typedef long long ll;
int main()
{
    ll a,b;
    char op;
    while (scanf("%I64d %I64d %c",&a,&b,&op)==3)
    {
        if (op=='^')
            printf("1\n");
        else
        {
            ll ans=1;
            for (int i=0;i<32;i++)
            {
                int x=a&1,y=b&1;
                a>>=1,b>>=1;
                if (op=='|')
                {
                    if (x && !y)
                    {
                        ans=0;
                        break;
                    }
                    if (x && y)
                        ans<<=1;
                }
                else
                {
                    if (!x && y)
                    {
                        ans=0;
                        break;
                    }
                    if (!x && !y)
                        ans<<=1;
                }
            }
            printf("%I64d\n",ans);
        }
    }
    return(0);
}

