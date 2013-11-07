#include <cstring>
#include <vector>
#include <string>
using namespace std;
struct DancingFoxes 
{ 
    int a[60][60]; 
    int minimalDays(vector <string> friendship) 
    { 
        int n=friendship.size(); 
        memset(a,63,sizeof(a)); 
        int inf=a[0][0]; 
        for (int i=1;i<=n;i++) 
        { 
            for (int j=1;j<=n;j++) 
                a[i][j]=friendship[i-1][j-1]=='Y'?1:inf; 
            a[i][i]=0; 
        } 
        for (int k=1;k<=n;k++) 
            for (int i=1;i<=n;i++) 
                for (int j=1;j<=n;j++) 
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]); 
        if (a[1][2]==inf) 
            return(-1); 
        int num=a[1][2]+1,ans=0; 
        while (num>2) 
        { 
            num=num/3*2+num%3; 
            ans++; 
        } 
        return(ans); 
    } 
};
int main(){}

