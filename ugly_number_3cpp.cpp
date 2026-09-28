class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int l=1, r=2000000001, mid;
        while(l<=r){
            mid=l+(r-l)/2;
            int ugly_amount=ugly_f(mid, a, b, c);
            if(ugly_amount==n)
                break;
            if(ugly_amount > n)
                r = mid-1;
            else
                l = mid+1;
        }
        while(mid>0){
            if(mid%a==0 || mid%b==0 || mid%c==0)
                return mid;
            mid--;
        }
        return 0;

    }
    int ugly_f(long long n, long long a, long long b, long long c){
        long long lcm_ab = lcm(a, b);
        long long lcm_ac = lcm(a, c);
        long long lcm_bc = lcm(b, c);
        long long lcm_abc = lcm(lcm(a, b), c);
        return n/a + n/b + n/c - n/lcm_ab - n/lcm_ac - n/lcm_bc + n/lcm_abc;

    }
};