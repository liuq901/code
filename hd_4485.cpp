#include <cstdio>
#include <cstring>
#include <cctype>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int id,n;
        scanf("%d%d",&id,&n);
        int x=0;
        getchar();
        while (1)
        {
            char ch;
            ch=getchar();
            if (!isdigit(ch))
                break;
            x=x*n+ch-'0';
            if (x>=10000000)
                x%=(n-1);
        }
        printf("%d %d\n",id,x%(n-1));
    }
    return(0);
}

