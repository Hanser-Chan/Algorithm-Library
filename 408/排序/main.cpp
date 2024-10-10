#include <iostream>
#include <vector>
#include <format>

using std::vector,std::cout,std::format;

class sort{
public:

    static void insertSort(vector<int> &nums) {
        cout << format("初始数组为：");
        for (auto i : nums) cout << format("{} ",i);
        cout << '\n';

        {   //排序部分
            int base;

            for (int i = 1; i < nums.size(); i++) {
                base = nums[i]; //以i为基准
                int j = i - 1;  //从i前面排序好的数组开始查
                while (j >= 0 && nums[j] > base) {  //找到合适的位置
                    nums[j + 1] = nums[j];
                    j--;
                }
                nums[j + 1] = base;   //在循环中多减了一次
            }
        }

        cout << format("插入排序结束。\n数组现在为：");
        for (auto i : nums) cout << format("{} ",i);
    }
    //折半查找插入位置再插入，这个算法感觉没什么存在的必要，完全多此一举
    static void biInsertSort(vector<int> &nums) {
        cout << format("初始数组为：");
        for (auto i : nums) cout << format("{} ",i);
        cout << '\n';


        {
            int base;
            for (int i = 1; i < nums.size(); i++) {
                base = nums[i];
                int l = 1,r = i - 1;    //折半查找左右指针
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (nums[mid] > base) r = mid-1; //mid大了往左半边找
                    else l = mid+1; //mid小了往右半边找
                }
                for (int j = i-1; j > r+1 ; j--) {
                    nums[j+1] = nums[j];
                }
                nums[r+1] = base;
            }
        }

        cout << format("折半插入排序结束。\n数组现在为：");
        for (auto i : nums) cout << format("{} ",i);
    }


    //形成相对有序的数组后插排
    static void shellSort(vector<int> &nums){
        cout << format("初始数组为：");
        for (auto i : nums) cout << format("{} ",i);
        cout << '\n';

        {
            int n = nums.size();
            for (int gap = n / 2; gap > 0; gap /= 2) {
                for (int i = gap; i < n; ++i) {
                    int base = nums[i];
                    int j;
                    //从表中第二个数据向前找
                    for (j = i; nums[j - gap] > base && j >= gap; j -= gap) {
                        nums[j] = nums[j - gap]; //更新数组
                    }
                    nums[j] = base;
                }
            }
        }

        cout << format("希尔排序结束。\n数组现在为：");
        for (auto i : nums) cout << format("{} ",i);
    }

    static void bubbleSort(vector<int> &nums) {
        cout << format("初始数组为：");
        for (auto i : nums) cout << format("{} ",i);
        cout << '\n';

        {
            for (int i = nums.size() - 1; i > 0; i--) {
                bool flag = false;
                for (int j = 0; j < i; j++) {
                    if (nums[j] > nums[j + 1]) {
                        std::swap(nums[j], nums[j + 1]);
                        flag = true;
                    }
                }
                if (!flag) break;
            }
        }

        cout << format("希尔排序结束。\n数组现在为：");
        for (auto i : nums) cout << format("{} ",i);
    }

    //快速排序 哨兵划分
    static int partition(vector<int> &nums, int left, int right) {
        int i = left,j = right;
        int base = nums[i]; //以左为基准元素
        while (i < j){
            while (i < j && nums[j] >= base) j--;    //从右往左找第一个小于base
            while (i < j && nums[i] <= base) i++;    //从左往右找第一个大于base
            std::swap(nums[i],nums[j]); //交换这两个，此时i对应的是小于base的数
        }
        std::swap(nums[i],nums[left]);  //交换最左和i，将小于base的挪到左边
        return i;   //返回此时的i，下一次要找i两边了
    }
    static void quickSort(vector<int> &nums, int left, int right) {
        if (left >= right) return;

        int pivot = partition(nums,left,right); //往下分直到数组只剩1个元素
        quickSort(nums,left,pivot-1);
        quickSort(nums,pivot + 1,right);
    }

    //归并排序 合并
    static void merge(vector<int> &nums, int left, int mid, int right) {

        int n1 = mid - left + 1; // 左子数组的长度
        int n2 = right - mid;    // 右子数组的长度

        // 创建临时数组
        std::vector<int> L(n1), R(n2);

        // 复制数据到临时数组中
        for (int i = 0; i < n1; ++i) {
            L[i] = nums[left + i];
        }
        for (int j = 0; j < n2; ++j) {
            R[j] = nums[mid + 1 + j];
        }

        // 合并临时数组到原数组中
        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                nums[k] = L[i];
                i++;
            } else {
                nums[k] = R[j];
                j++;
            }
            k++;
        }

        // 复制L[]的剩余元素
        while (i < n1) {
            nums[k] = L[i];
            i++;
            k++;
        }

        // 复制R[]的剩余元素
        while (j < n2) {
            nums[k] = R[j];
            j++;
            k++;
        }
    }
    static void mergeSort(vector<int> &nums, int left, int right) {
        if (left >= right) return;
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
};




int main() {
    vector<int> nums{4,1,3,1,5,2};
    //sort::bubbleSort(nums);


    //quick 专属
//    sort::quickSort(nums,0,nums.size()-1);
//    cout << format("快速排序结束。\n数组现在为：");
//    for (auto i : nums) cout << format("{} ",i);

    //merge 专属
    sort::mergeSort(nums,0,nums.size()-1);
    cout << format("归并排序结束。\n数组现在为：");
    for (auto i : nums) cout << format("{} ",i);
}
