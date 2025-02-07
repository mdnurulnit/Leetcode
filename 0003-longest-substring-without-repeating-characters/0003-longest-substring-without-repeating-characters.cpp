class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,n=s.length();
        if(n==0)return 0;
        int ans=INT_MIN;
        unordered_set<char>st;
        for(int r=0;r<n;r++){
            while(l<r && st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};