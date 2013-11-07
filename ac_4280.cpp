#include <cstdio>
void print(int x,int y,int z)
{
    printf("%d at four cents each\n",x);
    printf("%d at two for a penny\n",y);
    printf("%d at four for a penny\n\n",z);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int m=n*4;
        bool flag=false;
        static int id=0;
        printf("Case %d: ",++id);
        printf("%d pencils for %d cents\n",n,n);
        for (int i=1;i<=n;i++)
        {
            int money=m-i*16;
            if (money<=0)
                break;
            int sum=n-i,x=money-sum;
            if (x<sum && x>0)
            {
                flag=true;
                print(i,x,sum-x);
            }
        }
        if (!flag)
            printf("No solution found.\n\n");
    }
    return(0);
}

