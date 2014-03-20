#include <cstdio>
int idx,in[1010],out[1010],f[1010],b[1010],a[1010][1010];
bool hungary(int x)
{
    if (x==0)
        return(true);
    for (int i=1;i<=a[x][0];i++)
    {
        int y=a[x][i];
        if (f[y]==idx)
            continue;
        f[y]=idx;
        if (hungary(b[y]))
        {
            b[y]=x;
            return(true);
        }
    }
    return(false);
}
int main()
{
    int A,B;
    scanf("%d%d",&A,&B);
    int n=0,m=0,Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (y==0)
            in[++n]=x;
        else
            out[++m]=x;
    }
    if (n!=m)
        printf("Liar\n");
    else
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                int delta=out[j]-in[i];
                if (delta>=0 && (delta<=B || delta>=A))
                    a[i][++a[i][0]]=j;
            }
        bool flag=true;
        for (int i=1;i<=n;i++)
        {
            idx++;
            if (!hungary(i))
            {
                flag=false;
                break;
            }
        }
        if (!flag)
            printf("Liar\n");
        else
        {
            printf("No reason\n");
            for (int i=1;i<=n;i++)
                printf("%d %d\n",in[b[i]],out[i]);
        }
    }
    return(0);
}

