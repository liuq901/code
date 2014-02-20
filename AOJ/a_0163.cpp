#include <cstdio>
const int L[]={6,7,5,5,20,15};
const int a[7][7]={{0,300,500,600,700,1350,1650},
    {300,0,350,450,600,1150,1500},
    {500,350,0,250,400,1000,1350},
    {600,450,250,0,250,850,1300},
    {700,600,400,250,0,600,1150},
    {1350,1150,1000,850,600,0,500},
    {1650,1500,1350,1300,1150,500,0}};
int b[7][7];
bool check(int h,int m)
{
    return(h==17 && m>=30 || h==18 || h==19 && m<=30);
}
int main()
{
    for (int i=0;i<6;i++)
    {
        b[i][i]=0;
        b[i][i+1]=b[i+1][i]=L[i];
        for (int j=i+2;j<7;j++)
            b[i][j]=b[j][i]=b[i][j-1]+L[j-1];
    }
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int h1,m1,m,h2,m2;
        scanf("%d%d%d%d%d",&h1,&m1,&m,&h2,&m2);
        n--,m--;
        int ans=a[n][m];
        if ((check(h1,m1) || check(h2,m2)) && b[n][m]<=40)
            ans>>=1;
        printf("%d\n",(ans+49)/50*50);
    }
    return(0);
}

