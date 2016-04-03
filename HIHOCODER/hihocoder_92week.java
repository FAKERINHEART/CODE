import java.util.Scanner;
import java.math.*;

public class hihocoder_92week{
	public static long[] divid = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	public static BigInteger n;
	public static BigInteger u0;
	
	public static BigInteger multi_mod(BigInteger d, BigInteger m, BigInteger p)
	{
		BigInteger d1 = BigInteger.ONE;
		while(m.compareTo(BigInteger.ZERO) != 0)
		{
			if(m.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ONE) == 0) 
			{
				d1 = d1.multiply(d).mod(p);
				m = m.subtract(BigInteger.ONE);
			}
			m = m.divide(BigInteger.valueOf(2));
			d = d.pow(2).mod(p);
		}
		return d1;
	}
	public static boolean isprime()
	{
		if(n.compareTo(BigInteger.valueOf(2)) == 0) return true;
		if(n.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO) == 0) return false;
		
		BigInteger u, x, y;
		for(int i = 0; i < 12; i++)
		{
			if(BigInteger.valueOf(divid[i]).compareTo(n) < 0)
			{
				u = u0;
				x = multi_mod(BigInteger.valueOf(divid[i]), u, n);
					
				while(u.compareTo(n) < 0)
				{
					y = x.multiply(x).mod(n);
					if(y.compareTo(BigInteger.ONE) == 0 && x.compareTo(BigInteger.ONE) != 0 && x.compareTo(n.subtract(BigInteger.ONE)) != 0) return false; 
					x = y;
					u = u.multiply(BigInteger.valueOf(2));
				} 
				
				if(x.compareTo(BigInteger.ONE) != 0) return false;
			}
		}
		
		return true;
	}
	public static void main(String args[]){
		Scanner reader = new Scanner(System.in);
		Integer t = reader.nextInt();
		for(Integer i = 0; i < t; i++)
		{
			n = reader.nextBigInteger();
			u0 = n.subtract(BigInteger.ONE);
			while(u0.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO) == 0) u0 = u0.divide(BigInteger.valueOf(2));
			if(isprime()) System.out.println("Yes");
			else System.out.println("No");
		}
		
	}
}
