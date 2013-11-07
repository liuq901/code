#include <cstdio>
#include <cmath>
#include <complex>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0);
typedef complex <double> point;
double minx,miny,maxx,maxy;
void update(point a)
{
    minx=min(minx,a.real());
    maxx=max(maxx,a.real());
    miny=min(miny,a.imag());
    maxy=max(maxy,a.imag());
}
int main()
{
    minx=miny=1e10;
    maxx=maxy=-1e10;
    int x1,y1,x2,y2;
    bool flag=false;
    while (scanf("%d%d%d%d",&x1,&y1,&x2,&y2)==4)
    {
        point P(x1,y1),Q(x2,y2),A;
        A=P+(Q-P)*polar(1/sqrt(2.0),pi/4);
        update(P);
        update(Q);
        update(A);
        flag=true;
    }
    if (!flag)
        maxx=minx,maxy=miny;
    printf("%.4f %.4f\n",maxx-minx,maxy-miny);
    return(0);
}

