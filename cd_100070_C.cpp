#include <cstdio>
#include <map>
using namespace std;
FILE *in,*out;
map <int,int> M;
int main()
{
    in=fopen("right.in","r");
    out=fopen("right.out","w");
    int n,m;
    fscanf(in,"%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        int x;
        fscanf(in,"%d",&x);
        M[x]=i;
    }
    for (int i=1;i<=m;i++)
    {
        int x;
        fscanf(in,"%d",&x);
        fprintf(out,"%d\n",M[x]);
    }
    return(0);
}

