#include <cstdio>
int main()
{
    int a,b,c;
    while (scanf("%d%d%d",&a,&b,&c)==3)
    {
        int cnt=0;
        for (int i=1;i<=10;i++)
        {
            if (i==a || i==b || i==c || a+b+i>20)
                continue;
            cnt++;
        }
        printf("%s\n",cnt>=4?"YES":"NO");
    }
    return(0);
}

