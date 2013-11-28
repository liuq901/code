#include <cstdio>
#include <cstring>
#include <cmath>
char s[10];
int main()
{
    int n;
    double z;
    while (scanf("%d%lf",&n,&z)==2)
    {
        sprintf(s,"%f",jn(n,z));
        if (strcmp(s,"-0.000000")==0)
            printf("0.000000\n");
        else
            printf("%s\n",s);
    }
    return(0);
}

