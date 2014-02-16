#include <cstdio>
int num[1000010],vis[1000010];
int main()
{
    int p,q,idx=0;
    while (scanf("%d%d",&p,&q)==2)
    {
        idx++;
        int pos=0,final=-1;
        while (1)
        {
            vis[p]=idx;
            num[p]=++pos;
            printf("%d",p*10/q);
            p=p*10%q;
            if (vis[p]==idx || p==0)
            {
                if (vis[p]==idx)
                    final=num[p];
                break;
            }
        }
        printf("\n");
        if (final!=-1)
        {
            for (int i=1;i<=pos;i++)
                printf("%c",i<final?' ':'^');
            printf("\n");
        }
    }
    return(0);
}

