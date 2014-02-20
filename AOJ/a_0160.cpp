#include <cstdio>
const int a[]={60,80,100,120,140,160,1<<30};
const int b[]={2,5,10,15,20,25,1<<30};
const int c[]={600,800,1000,1200,1400,1600,0};
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int x,y,z,w;
            scanf("%d%d%d%d",&x,&y,&z,&w);
            x+=y+z;
            for (int i=0;i<7;i++)
                if (x<=a[i] && w<=b[i])
                {
                    ans+=c[i];
                    break;
                }
        }
        printf("%d\n",ans);
    }
    return(0);
}

