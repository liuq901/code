#include <cstdio>
int main()
{
    int id;
    double m,l;
    while (scanf("%d,%lf,%lf",&id,&m,&l)==3)
        if (m/(l*l)>=25)
            printf("%d\n",id);
    return(0);
}

