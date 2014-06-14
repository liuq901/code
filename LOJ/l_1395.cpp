#include <cstdio>
double f[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        double out=0,in=0;
        int cout=0,cin=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x>0)
                out+=x,cout++;
            else
                in-=x,cin++;
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (cout==0)
            printf("-1\n");
        else
        {
            out/=cout;
            if (cin)
                in/=cin;
            if (cin<m)
                m=cin;
            f[m]=(cout*out+(cin-m)*in)/(n-cin);
            for (int i=m-1;i>=0;i--)
                f[i]=cout*out/(n-i)+(cin-i)*(f[i+1]+in)/(n-i);
            printf("%.10f\n",f[0]);
        }
    }
    return(0);
}

