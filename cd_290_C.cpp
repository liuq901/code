#include <cstdio>
int main()
{
    int tux,foo=0,bar=0,baz=0,quz=1;
    scanf("%d",&tux);
    for (int i=0;i<tux;i++)
    {
        int pur;
        scanf("%d",&pur);
        foo+=pur;
        bar+=1;
        if (foo*quz>bar*baz)
        {
            baz=foo;
            quz=bar;
        }
    }
    printf("%.10f\n",baz/double(quz));
    return(0);
}

