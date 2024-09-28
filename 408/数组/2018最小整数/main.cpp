#include<iostream>
#include<unordered_map>
#include<format>
#include<vector>

using std::cout,std::format,std::vector;

int mini(int * nums){
    size_t size = sizeof(nums);
    int *hash = new int[size]();
    int flag{-1};

    for (size_t i = 0; i < size; i++)
    {
        if (nums[i] > 0 && nums[i] <= size)
        {
            hash[nums[i] - 1] = 1;
        }
        
    }
    
    for (size_t i = 0; i < size; i++)
    {
        if (hash[i] == 0)
        {
            flag = i + 1;
            break;
        }
        
    }
    
    delete[] hash;
    return flag;
}

int mini2(const vector<int> &nums){
    size_t size = nums.size(); 
    std::unordered_map<int, bool> hash; 

    int flag {-1};
    
    for (size_t i = 0; i < size; i++) {
        if (nums[i] > 0 ) {
            hash[nums[i] - 1] = true; 
        }
    }

    for (size_t i = 1; i <= size; i++) {
        if (hash.find(i) == hash.end()) { 
            flag = i + 1;
            break;
        }
    }

    return flag; 
}

int main(){
    int nums[] = {-5,3,2,3};
    int nums2[] = {1,2,3};
    vector<int> numss{-5,3,2,3};
    vector<int> numss2{1,2,3};
    cout << format("最小未出现正整数为{}",mini2(numss2));
}