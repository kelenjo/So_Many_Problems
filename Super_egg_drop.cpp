class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> x(k + 1, vector<int>(n + 1, -1));
        return find(k, n, x);

    }
    int find(int k, int n, vector<vector<int>>& x){
        if(n==0 || n==1) 
            return n;
        if(k==1)
            return n;
        if(x[k][n]!=-1)
            return x[k][n];
        
        int ans=10001, l=1, r=n, mid;
        while(l<=r){
            mid=l+(r-l)/2;
            int l_ans = find(k-1, mid-1, x);
            int r_ans = find(k, n-mid, x);

            if(l_ans==r_ans){
                ans = min(ans, 1 + l_ans);
                break;
            }
            if(l_ans>r_ans)
                r=mid-1;
            else
                l=mid+1;

            ans = min(ans, 1 + max(l_ans, r_ans));
        }

        x[k][n] = ans;
        return x[k][n];
    }
};
