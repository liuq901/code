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
    void run()
    {
        Scanner in=new Scanner(System.in);
        int T=in.nextInt();
        while (T-->0)
        {
            BigInteger H=in.nextBigInteger();
            BigInteger L=in.nextBigInteger();
            BigInteger h=in.nextBigInteger();
            BigInteger left=L.multiply(L).add(H.multiply(H));
            BigInteger right=h.multiply(H).multiply(BigInteger.valueOf(4));
            BigInteger l=BigInteger.ZERO,r=BigInteger.ONE.shiftLeft(500),ans=BigInteger.ZERO;
            while (l.compareTo(r)<=0)
            {
                BigInteger mid=l.add(r).shiftRight(1);
                if (left.compareTo(right.multiply(mid).multiply(mid.add(BigInteger.ONE)))>=0)
                {
                    ans=mid;
                    l=mid.add(BigInteger.ONE);
                }
                else
                    r=mid.subtract(BigInteger.ONE);
            }
            System.out.println(ans.add(BigInteger.ONE));
        }
    }
}
*/
int main(){}


