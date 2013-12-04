#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a[3]={1,0,0};
    char x,y;
    while (scanf("%c,%c ",&x,&y)==2)
        swap(a[x-'A'],a[y-'A']);
    printf("%c\n",max_element(a,a+3)-a+'A');
    return(0);
}

