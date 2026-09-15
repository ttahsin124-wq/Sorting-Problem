class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
    unordered_set<int>result;
    for(int x:arr)
    {
        if(result.count(2*x) or (x%2==0 and result.count(x/2)))
        {
            return true;
        }
        result.insert(x);
    }
    return  false;
    
    }
};