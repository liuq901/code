#include <cstdio>
int main()
{
    int x,y;
    char ch;
    scanf("%d%c",&x,&ch);
    y=ch-'A'+1;
    if (x<=2)
        printf("%s\n",y==1 || y==4?"window":"aisle");
    else if (x<=20)
        printf("%s\n",y==1 || y==6?"window":"aisle");
    else
        printf("%s\n",y==1 || y==11?"window":y==3 || y==4 || y==7 || y==8?"aisle":"neither");
    return(0);
}

