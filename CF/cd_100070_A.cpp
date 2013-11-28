#include <cstdio>
FILE *in,*out;
int main()
{
    in=fopen("absum.in","r");
    out=fopen("absum.out","w");
    int a,b;
    fscanf(in,"%d%d",&a,&b);
    fprintf(out,"%d\n",a+b);
    fclose(in),fclose(out);
    return(0);
}

