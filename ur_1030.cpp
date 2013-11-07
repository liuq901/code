#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#define SQR(x) ((x)*(x))
using namespace std;
string s;
void read(int &a,int &b,int &c,char &ch)
{
    cin>>a>>ch>>b>>ch>>c>>ch>>ch;
}
void GETS(int n)
{
    if (n==0)
        return;
    getline(cin,s);
    GETS(n-1);
}
double Dist(double lati1,double longi1,double lati2,double longi2,double R)
{
    double pi=acos(-1.0);
    lati1*=pi/180,longi1*=pi/180,lati2*=pi/180,longi2*=pi/180;
    double x1=cos(lati1)*sin(longi1),y1=cos(lati1)*cos(longi1),z1=sin(lati1);
    double x2=cos(lati2)*sin(longi2),y2=cos(lati2)*cos(longi2),z2=sin(lati2);
    double theta=acos(x1*x2+y1*y2+z1*z2);
    return(R*theta);
}
int main()
{
    GETS(3);
    double l1,w1,l2,w2;
    int a,b,c;
    char ch;
    read(a,b,c,ch);
    l1=(a+b/60.0+c/3600.0)*(ch=='N'?1:-1);
    GETS(1);
    cin>>s;
    read(a,b,c,ch);
    w1=(a+b/60.0+c/3600.0)*(ch=='E'?1:-1);
    GETS(2);
    read(a,b,c,ch);
    l2=(a+b/60.0+c/3600.0)*(ch=='N'?1:-1);
    GETS(1);
    cin>>s;
    read(a,b,c,ch);
    w2=(a+b/60.0+c/3600.0)*(ch=='E'?1:-1);
    double ans=Dist(l1,w1,l2,w2,6875/2.0);
    printf("The distance to the iceberg: %.2f miles.\n",ans);
    if (int(ans*1000)<99995)
        printf("DANGER!\n");
    return(0);
}

