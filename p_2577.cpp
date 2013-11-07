#include <cstdio>
int reg[20],mem[1010];
int main()
{
    int n=0,x;
    while (scanf("%d",&x)==1)
        mem[n++]=x;
    int pc=0;
    for (int i=1;;i++)
    {
        int a=mem[pc]/100,b=mem[pc]/10%10,c=mem[pc]%10;
        pc++;
        if (a==1)
        {
            printf("%d\n",i);
            break;
        }
        else if (a==2)
            reg[b]=c;
        else if (a==3)
            reg[b]=(reg[b]+c)%1000;
        else if (a==4)
            reg[b]=(reg[b]*c)%1000;
        else if (a==5)
            reg[b]=reg[c];
        else if (a==6)
            reg[b]=(reg[b]+reg[c])%1000;
        else if (a==7)
            reg[b]=(reg[b]*reg[c])%1000;
        else if (a==8)
            reg[b]=mem[reg[c]];
        else if (a==9)
            mem[reg[c]]=reg[b];
        else if (reg[c])
            pc=reg[b];
    }
    return(0);
}

