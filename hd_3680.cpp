/*
Java:
import java.io.*;
import java.math.*;
import java.util.*;
public class Main
{
    public static void main(String args[])
    {
        new Main().run();
    }
    BigInteger zero=BigInteger.ZERO;
    BigInteger one=BigInteger.ONE;
    BigInteger two=one.add(one);
    BigInteger three=two.add(one);
    void run()
    {
        Scanner in=new Scanner(System.in);
        while (true)
        {
            BigInteger n=in.nextBigInteger(),m=in.nextBigInteger();
            if (n.equals(zero) && m.equals(zero))
                break;
            System.out.println(solve(n,m));
        }
    }
    BigInteger solve(BigInteger n,BigInteger m)
    {
        int len=n.bitLength();
        BigInteger f[][]=new BigInteger[len+1][3];
        BigInteger x=n;
        for (int i=len;i>=0;i--)
        {
            for (int j=0;j<=2;j++)
                f[i][j]=x.add(BigInteger.valueOf(j-1)).subtract(m).abs();
            x=x.shiftRight(1);
        }
        for (int i=1;i<=len;i++)
            if (!n.testBit(len-i))
            {
                f[i][0]=f[i][0].min(f[i-1][0].add(two)).min(f[i-1][1].add(two)).min(f[i-1][2].add(three));
                f[i][1]=f[i][1].min(f[i-1][0].add(two)).min(f[i-1][1].add(one)).min(f[i-1][2].add(two));
                f[i][2]=f[i][2].min(f[i-1][0].add(three)).min(f[i-1][1].add(two)).min(f[i-1][2].add(two));
            }
            else
            {
                f[i][0]=f[i][0].min(f[i-1][0].add(two)).min(f[i-1][1].add(one)).min(f[i-1][2].add(two));
                f[i][1]=f[i][1].min(f[i-1][0].add(three)).min(f[i-1][1].add(two)).min(f[i-1][2].add(two));
                f[i][2]=f[i][2].min(f[i-1][0].add(three)).min(f[i-1][1].add(two)).min(f[i-1][2].add(one));
            }
        return(f[len][1].min(f[len][0].min(f[len][2]).add(one)));
    }
}
*/
int main(){}

