#include <cstdio>
#include <cmath>
const double eps=1e-10;
const int myMAX=300;
const int oo=19930131;
double myA[myMAX+1][myMAX+1],mytA[myMAX+1][myMAX+1];
double myb[myMAX+1],mytb[myMAX+1],myc[myMAX+1],mytc[myMAX+1];
int myN[myMAX+1+1],myB[myMAX+1+1];
int n,m;
double myV;
bool read()
{
    if (scanf("%d%d",&n,&m)!=2)
        return(false);
    for (int i=1;i<=n;i++)
        scanf("%lf",&myc[i]);
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
            scanf("%lf",&myA[n+i][j]);
        scanf("%lf",&myb[n+i]);
    }
    return(true);
}
void pivot(int l,int e)
{
    mytb[e]=myb[l]/myA[l][e];
    mytA[e][l]=1/myA[l][e];
    for (int i=1;i<=myN[0];i++)
        if (myN[i]!=e)
            mytA[e][myN[i]]=myA[l][myN[i]]/myA[l][e];
    for (int i=1;i<=myB[0];i++)
    {
        mytb[myB[i]]=myb[myB[i]]-myA[myB[i]][e]*mytb[e];
        mytA[myB[i]][l]=-myA[myB[i]][e]*mytA[e][l];
        for (int j=1;j<=myN[0];j++)
            if (myN[j]!=e)
                mytA[myB[i]][myN[j]]=myA[myB[i]][myN[j]]-mytA[e][myN[j]]*myA[myB[i]][e];
    }
    myV+=mytb[e]*myc[e];
    mytc[l]=-mytA[e][l]*myc[e];
    for (int i=1;i<=myN[0];i++)
        if (myN[i]!=e)
            mytc[myN[i]]=myc[myN[i]]-mytA[e][myN[i]]*myc[e];
    for (int i=1;i<=myN[0];i++)
        if (myN[i]==e)
            myN[i]=l;
    for (int i=1;i<=myB[0];i++)
        if (myB[i]==l)
            myB[i]=e;
    for (int i=1;i<=myB[0];i++)
    {
        for (int j=1;j<=myN[0];j++)
            myA[myB[i]][myN[j]]=mytA[myB[i]][myN[j]];
        myb[myB[i]]=mytb[myB[i]];
    }
    for (int i=1;i<=myN[0];i++)
        myc[myN[i]]=mytc[myN[i]];
}
bool opt()
{
    while (1)
    {
        int e=myMAX+1;
        for (int i=1;i<=myN[0];i++)
            if (myc[myN[i]]>eps && myN[i]<e)
                e=myN[i];
        if (e==myMAX+1)
            break;
        double delta=oo;
        int l=myMAX+1;
        for (int i=1;i<=myB[0];i++)
            if (myA[myB[i]][e]>eps)
            {
                double tmp=myb[myB[i]]/myA[myB[i]][e];
                if (delta==oo || tmp<delta || tmp==delta && myB[i]<l)
                {
                    delta=tmp;
                    l=myB[i];
                }
            }
        if (l==myMAX+1)
            return(false);
        pivot(l,e);
    }
    return(true);
}
void init()
{
    myN[0]=myB[0]=0;
    for (int i=1;i<=n;i++)
        myN[++myN[0]]=i;
    for (int i=1;i<=m;i++)
        myB[++myB[0]]=n+i;
    myV=0;
}
int main()
{
    while (read())
    {
        init();
        opt();
        printf("Nasa can spend %d taka.\n",int(ceil(myV*m)));
    }
    return(0);
}

