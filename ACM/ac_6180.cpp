#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0);
const double rotRate=2*pi*1.0027379093/86400;
typedef double matrix[5][5];
struct point
{
    double x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
};
inline double sqr(double x)
{
    return(x*x);
}
inline point det(const point &a,const point &b)
{
    return(point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
inline point calc(double alpha,double delta)
{
    return(point(cos(alpha)*cos(delta),sin(alpha)*cos(delta),sin(delta)));
}
int n;
double alpha[110],delta[110];
point A1,A2,A3,B1,B2,B3;
point getBaseStar(point &A,point &B)
{
    int id,t;
    double Alpha,Delta;
    scanf("%d%d%lf%lf",&t,&id,&Alpha,&Delta);
    Alpha=Alpha/180*pi;
    Delta=Delta/180*pi;
    A=calc(alpha[id]-t*rotRate,delta[id]);
    B=calc(Alpha,Delta);
}
matrix A,B,trans;
void fill(matrix a,int column,const point &P)
{
    a[1][column]=P.x,a[2][column]=P.y,a[3][column]=P.z;
}
void reverseMatrix(matrix a)
{
    double c[5][10]={0};
    for (int i=1;i<=3;i++)
    {
        for (int j=1;j<=3;j++)
            c[i][j]=a[i][j];
        c[i][i+3]=1;
    }
    for (int i=1;i<=3;i++)
    {
        for (int j=i+1;j<=3;j++)
            if (fabs(c[j][i])>fabs(c[i][i]))
                for (int k=1;k<=6;k++)
                    swap(c[i][k],c[j][k]);
        double p=c[i][i];
        for (int j=1;j<=6;j++)
            c[i][j]/=p;
        for (int j=1;j<=3;j++)
        {
            if (i==j)
                continue;
            p=c[j][i]/c[i][i];
            for (int k=1;k<=6;k++)
                c[j][k]-=c[i][k]*p;
        }
    }
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
            a[i][j]=c[i][j+3];
}
void getMatrix()
{
    fill(A,1,A1),fill(A,2,A2),fill(A,3,A3);
    fill(B,1,B1),fill(B,2,B2),fill(B,3,B3);
    reverseMatrix(A);
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
        {
            trans[i][j]=0;
            for (int k=1;k<=3;k++)
                trans[i][j]+=B[i][k]*A[k][j];
        }
}
point transpose(const point &P)
{
    double x=trans[1][1]*P.x+trans[1][2]*P.y+trans[1][3]*P.z;
    double y=trans[2][1]*P.x+trans[2][2]*P.y+trans[2][3]*P.z;
    double z=trans[3][1]*P.x+trans[3][2]*P.y+trans[3][3]*P.z;
    return(point(x,y,z));
}
void getAns(int t,int id)
{
    point P=calc(alpha[id]-t*rotRate,delta[id]);
    point Q=transpose(P);
    double Delta=atan2(Q.z,sqrt(sqr(Q.x)+sqr(Q.y)));
    double Alpha=atan2(Q.y,Q.x);
    if (Alpha<0)
        Alpha+=pi;
    if (Delta<0)
        printf("NOT VISIBLE\n");
    else
        printf("%.1f %.1f\n",Alpha/pi*180,Delta/pi*180);
}
int main()
{
    int Q;
    scanf("%d%d",&n,&Q);
    for (int i=1;i<=n;i++)
    {
        int id;
        scanf("%d",&id);
        scanf("%lf%lf",&alpha[id],&delta[id]);
        alpha[id]=alpha[id]/180*pi;
        delta[id]=delta[id]/180*pi;
    }
    while (Q--)
    {
        int id,m;
        scanf("%d%d",&id,&m);
        printf("%d %d\n",id,m);
        getBaseStar(A1,B1);
        getBaseStar(A2,B2);
        A3=det(A1,A2),B3=det(B1,B2);
        getMatrix();
        while (m--)
        {
            int id,t,x;
            scanf("%d%d%d",&id,&t,&x);
            printf("%d ",id);
            getAns(t,x);
        }
    }
    return(0);
}

