#include <cstdio>
bool f[4];
int main()
{
    int a[4];
    while (scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3])==4)
    {
        int T;
        scanf("%d",&T);
        while (T--)
        {
            int b[4];
            scanf("%d%d%d%d",&b[0],&b[1],&b[2],&b[3]);
            f[0]=f[1]=f[2]=f[3]=false;
            int A,B;
            A=B=0;
            for (int i=0;i<4;i++)
                if (a[i]==b[i])
                {
                    f[i]=true;
                    A++;
                }
            for (int i=0;i<4;i++)
            {
                if (b[i]==a[i])
                    continue;
                for (int j=0;j<4;j++)
                {
                    if (f[j])
                        continue;
                    if (b[i]==a[j])
                    {
                        f[j]=true;
                        B++;
                        break;
                    }
                }
            }
            printf("%dA%dB\n",A,B);
        }
    }
    return(0);
}

