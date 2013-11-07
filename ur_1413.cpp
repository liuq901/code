#include <cstdio>
#include <cstring>
#include <cmath>
const double x=1/sqrt(2.0);
const double c[10][2]={{0},{-x,-x},{0,-1},{x,-x},{-1,0},{0,0},{1,0},{-x,x},{0,1},{x,x}};
char buf[1000010];
int main()
{
    double x0=0,y0=0;
    scanf("%s",buf);
    int len=strlen(buf);
    for (int i=0;i<len;i++)
    {
        char ch=buf[i];
        if (ch=='0')
            break;
        int k=ch-'0';
        x0+=c[k][0],y0+=c[k][1];
    }
    printf("%.10f %.10f\n",x0,y0);
    return(0);
}

