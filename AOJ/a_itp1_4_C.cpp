#include <cstdio>
int main()
{
    while (1)
    {
        int a,b;
        char op;
        scanf("%d %c %d",&a,&op,&b);
        bool flag=false;
        switch (op)
        {
        case '+':
            printf("%d\n",a+b);
            break;
        case '-':
            printf("%d\n",a-b);
            break;
        case '*':
            printf("%d\n",a*b);
            break;
        case '/':
            printf("%d\n",a/b);
            break;
        default:
            flag=true;
            break;
        }
        if (flag)
            break;
    }
    return(0);
}

