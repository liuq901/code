#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    if (6*n>100000)
        printf("TOO LONG\n");
    else if (n==1)
        printf("a\nb\nc\n");
    else
    {
        char a[10]="abc";
        while (1)
        {
            for (int i=0;i<n;i++)
                printf("%c",a[i%3]);
            printf("\n");
            if (!next_permutation(a,a+3))
                break;
        }
    }
    return(0);
}

