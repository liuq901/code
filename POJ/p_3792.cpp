#include <cstdio>
#include <cstdlib>
struct cube
{
    int x,y,z;
    cube(){}
    void in()
    {
        scanf("%d,%d,%d",&x,&y,&z);
    }
};
int operator -(cube a,cube b)
{
    return(abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z));
}
cube a[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            a[i].in();
        int ans=6*n,flag=0;
        for (int i=2;i<=n;i++)
        {
            int sum=0;
            for (int j=1;j<i;j++)
            {
                if (a[i]-a[j]==1)
                    sum+=2;
                if (a[i]-a[j]==0)
                {
                    sum=0;
                    break;
                }
            }
            if (sum==0)
            {
                flag=i;
                break;
            }
            ans-=sum;
        }
        static int id=0;
        printf("%d ",++id);
        if (flag==0)
            printf("%d\n",ans);
        else
            printf("NO %d\n",flag);
    }
    return(0);
}

