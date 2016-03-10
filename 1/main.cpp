#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int,int> needmap;
        for(std::vector<int>::iterator iter=nums.begin();iter!=nums.end();++iter)
        {
          if (needmap.find(*iter)!=needmap.end())
          {
            result.push_back(needmap[*iter]);
            result.push_back(iter-nums.begin());
            break;  
          }
          else
          {
            needmap[target-(*iter)]=iter-nums.begin();
          }
        }
        return result;
    }
    
};

int main()
{
  std::vector<int> num;
  num.push_back(2);
  num.push_back(7);
  num.push_back(11);
  num.push_back(15);
  Solution sol;
  std::vector<int> res=sol.twoSum(num,26);
  std::cout<<res[0]<<","<<res[1]<<std::endl;
  return 0;
  

}
