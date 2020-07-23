class Solution{
public:
  vector<int> singleNumber3(vector<int>& nums){
  vector<int> output;
  int temp = 0;
  int res1 =0;
  int res2 =0;
  
  for(int i : nums)
  {
    temp = temp ^ i;
  }
  
  int mask = 1;
  
  while((temp & mask) ==0){
  mask = mask << 1;
  }
  
  for(int i : nums){
  if((mask & i) == 0)
  res1 = res1 ^ i;
  else
  res2 = res2 ^ i;
  }
  output.push_back(res1);
  output.push_back(res2);
  return output;
  }
};
