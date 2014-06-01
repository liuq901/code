#include <cstdio>
#include <cstring>
const int n=1001;
int c[1010][1010];
bool a[1010][1010];
void insert(int x,int y)
{
    for (int i=x;i<=n;i+=i&-i)
        for (int j=y;j<=n;j+=j&-j)
            c[i][j]++;
}
int query(int x,int y)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        for (int j=y;j;j-=j&-j)
            ret+=c[i][j];
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
        int Q;
        scanf("%d",&Q);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int op;
            scanf("%d",&op);
            if (op==0)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                x++,y++;
                if (!a[x][y])
                {
                    a[x][y]=true;
                    insert(x,y);
                }
            }
            else
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x2++,y2++;
                printf("%d\n",query(x2,y2)-query(x1,y2)-query(x2,y1)+query(x1,y1));
            }
        }
    }
    return(0);
}

