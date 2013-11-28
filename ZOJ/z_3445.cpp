/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
    public static void main(String args[])
    {
        new Main().run();
    }
    void run()
    {
        BigDecimal c[][]=new BigDecimal[120][120];
        for (int i=0;i<=100;i++)
        {
            c[i][0]=c[i][i]=BigDecimal.ONE;
            for (int j=1;j<i;j++)
                c[i][j]=c[i-1][j-1].add(c[i-1][j]);
        }
        Scanner in=new Scanner(System.in);
        while (in.hasNext())
        {
            int n=in.nextInt();
            BigDecimal ans=BigDecimal.ZERO,one=BigDecimal.ONE;
            for (int i=0;i<=n;i++)
                ans=ans.add(sqrt(one.divide(c[n][i],120,1)));
            System.out.println(ans.setScale(100,4));
        }
    }
    BigDecimal sqrt(BigDecimal a)
    {
        BigDecimal x=a,two=BigDecimal.valueOf(2);
        for (int i=1;i<60;i++)
            x=(x.add(a.divide(x,120,1))).divide(two,120,1);
        return(x);
    }
}
*/
int main(){}

