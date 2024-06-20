class Solution {
public:
vector<vector<int>> ans;
vector<int>ds;
void helper(int ind,int k,vector<int>&arr){
        if(k==0){ 
            ans.push_back(ds);
            return;
        }
    for(int i=ind;i<arr.size();i++){
        if(i>ind and arr[i]==arr[i-1]) continue;
        if(arr[i]>k) break;
        ds.push_back(arr[i]);
        helper(i+1,k-arr[i],arr);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        helper(0,k,arr);
        return ans;
    }
};