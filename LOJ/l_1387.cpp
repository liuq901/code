#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int Q,sum=0;
        scanf("%d",&Q);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            char op[10];
            scanf("%s",op);
            if (op[0]=='d')
            {
                int x;
                scanf("%d",&x);
                sum+=x;
            }
            else
                printf("%d\n",sum);
        }
    }
    return(0);
}

