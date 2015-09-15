import java.util.*;
import java.math.*;

class Main{
	static ArrayList<Integer> nums;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		nums = new ArrayList<Integer>();
		while(sc.hasNext()){
			int cur = sc.nextInt();
			if(cur == -999999){
				solve();
			}
			else{
				nums.add(cur);
			}
		}
	}
	public static void solve(){
		ArrayList<BigInteger> dp_min = new ArrayList<BigInteger>();
		ArrayList<BigInteger> dp_max = new ArrayList<BigInteger>();
		dp_min.add(BigInteger.valueOf(nums.get(0)));
		dp_max.add(BigInteger.valueOf(nums.get(0)));
		BigInteger a,b,c;
		BigInteger max=BigInteger.valueOf(nums.get(0));
		for(int i = 1; i < nums.size(); i++){
				c=BigInteger.valueOf(nums.get(i));
				a=dp_min.get(i-1).multiply(c);
				b=dp_max.get(i-1).multiply(c);
				dp_min.add(a.min(b.min(c)));
				dp_max.add(a.max(b.max(c)));
				if(dp_max.get(i).compareTo(max)==1)
					max=dp_max.get(i);
		}
		System.out.println(max.toString());
		nums.clear();
	}
}
