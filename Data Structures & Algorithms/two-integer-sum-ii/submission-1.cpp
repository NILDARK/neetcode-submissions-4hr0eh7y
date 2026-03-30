class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i,j;
        i=0;
        j = numbers.size()-1;
        while(i<j){
            int sm = numbers[i]+numbers[j];
            if(sm==target) return {i+1,j+1};
            else if(sm>target) --j;
            else ++i;
        }
    }
};
