class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for(int i=0;i<numbers.size()-1;++i){
            auto possible_pos = lower_bound(numbers.begin()+i+1, numbers.end(), target-numbers[i]);
            int pos = possible_pos - numbers.begin();
            if((numbers[pos]+numbers[i])==target){
                return {i+1,pos+1};
            }
        }
    }
};
