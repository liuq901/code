#include <cstdio>
#include <algorithm>
using namespace std;
FILE *in,*out;
int main()
{
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");
    int T,K;
    fscanf(in,"%d%d",&T,&K);
    K++;
    while (T--)
    {
        int n,m;
        fscanf(in,"%d%d",&n,&m);
        if (n>m)
            swap(n,m);
        if (n%K==0)
            fprintf(out,"+\n");
        else
        {
            int t=n+m+n/K;
            if (K==2)
                t-=n/K;
            fprintf(out,"%s\n",t&1?"+":"-");
        }
    }
    fclose(in),fclose(out);
    return(0);
}

