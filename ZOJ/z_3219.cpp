#include <cstdio>
#include <cstring>
double f[110][110],g[110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int A,B,C,D;
        double p;
        scanf("%d%d%d%d%lf",&A,&B,&C,&D,&p);
        memset(f,0,sizeof(f));
        for (int tmp=0;tmp<=100;tmp++)
        {
            memset(g,0,sizeof(g));
            for (int i=0;i<=100;i++)
                for (int j=0;j<=100;j++)
                {
                    if (i>=C)
                        g[i][j]+=f[i-C][j+C]*p;
                    if (j<D)
                        g[i][j]+=1-p;
                    else
                        g[i][j]+=f[i+D][j-D]*(1-p);
                }
            memcpy(f,g,sizeof(g));
        }
        printf("%.2f\n",f[A][B]);
    }
    return(0);
}

