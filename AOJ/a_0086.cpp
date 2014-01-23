#include <cstdio>
#include <cstring>
int d[110];
int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b)==2)
    {
        memset(d,0,sizeof(d));
        while (1)
        {
            d[a]++;
            d[b]++;
            scanf("%d%d",&a,&b);
            if (a==0 && b==0)
                break;
        }
        bool flag=true;
        for (int i=3;i<=100;i++)
            if (d[i]&1)
            {
                flag=false;
                break;
            }
        if (d[1]%2==0 || d[2]%2==0)
            flag=false;
        printf("%s\n",flag?"OK":"NG");
    }
    return(0);
}

