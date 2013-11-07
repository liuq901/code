#include <cstdio>
const int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,0};
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;;i++)
        if (p[i]==n)
        {
            printf("%s\n",p[i+1]==m?"YES":"NO");
            break;
        }
    return(0);
}

