#include <cstdio>
int main()
{
    int r1,r2,c1,c2,d1,d2;
    scanf("%d%d%d%d%d%d",&r1,&r2,&c1,&c2,&d1,&d2);
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++)
        {
            if (i==j)
                continue;
            for (int k=1;k<=9;k++)
            {
                if (i==k || j==k)
                    continue;
                for (int l=1;l<=9;l++)
                {
                    if (i==l || j==l || k==l)
                        continue;
                    if (i+j==r1 && k+l==r2 && i+k==c1 & j+l==c2 && i+l==d1 && j+k==d2)
                    {
                        printf("%d %d\n%d %d\n",i,j,k,l);
                        goto last;
                    }
                }
            }
        }
    printf("-1\n");
last:
    return(0);
}

