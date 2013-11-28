#include <cstdio>
const int c[]={0,10,50,100,500,1000,5000};
int main()
{
    int upper,lower;
    bool flag=false;
    lower=upper=0;
    for (int i=1;i<=6;i++)
    {
        int x;
        scanf("%d",&x);
        upper+=c[i]*x;
        lower+=c[i]*x;
        if (x!=0 && !flag)
        {
            flag=true;
            lower-=c[i];
        }
    }
    int p;
    scanf("%d",&p);
    upper/=p,lower/=p;
    printf("%d\n",upper-lower);
    for (int i=lower+1;i<=upper;i++)
        printf("%d%c",i,i==upper?'\n':' ');
    return(0);
}

