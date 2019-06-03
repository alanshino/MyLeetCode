// First The C programing language

int removeElement(int* nums, int numsSize, int val){
    /*
    int i, return_val = numsSize, pc = 1, yes = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            return_val--;
            if ((i + 1) < numsSize) {
                if (nums[i + 1] != val) {
                    nums[i] = nums[i + 1];
                }else {
                    pc++;
                    yes++;
                }
            }else if ((i + 1) == numsSize) {
                return return_val;
            }
        }else if (yes) {
            nums[i - pc] = nums[i];
        }
    }
    return return_val;
    */
    /**
        return_val 記錄下剩餘的字數
        yes 記錄下移除指定數字後的位置重組偏移量
    */
    int i, return_val = numsSize, pc = 1, yes = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            return_val--;
            yes++;
        }else if (yes) {
            nums[i - yes] = nums[i];
        }
    }
    return return_val;
}

int removeElement(int* nums, int numsSize, int val){
    int i, return_val = numsSize, pc = 1, yes = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            return_val--;
            yes++;
        }else if (yes) {
            nums[i - yes] = nums[i];
        }
    }
    return return_val;
}

/**

*/

int removeElement(int* nums, int numsSize, int val){

    int i = 0, j = numsSize;

    while(i<j){
        if(nums[i] == val){
            nums[i] = nums[j-1];
            j--;
        }
        else{
            i++;
        }
    }

    return j;
}

/** Java

class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] == val) {
                continue;
            } else {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
}

class Solution {
    public int removeElement(int[] nums, int val) {

        List<Integer> remain = new ArrayList<>();
        for(int num : nums){
            if(num == val) {
                continue;
            }
            remain.add(num);
        }
        for(int i = 0; i < remain.size(); i++) {
            nums[i] = remain.get(i);
        }

        return remain.size();
    }
}

*/

/** C++

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), val));
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator i = nums.begin();
        while(i != nums.end()) {
            if(*i == val)
                nums.erase(i);
            else
                i++;
        }

        return nums.size();
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int i = 0;
        while (i < nums.size() && nums[i] != val) {
            i++;
        }
        if (i == nums.size()) return nums.size();
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] != val) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
        return i;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

*/

/** Go

func removeElement(nums []int, val int) int {
	sort.Ints(nums)
	result := searchRange(nums, val)
	if result[0] != -1 {
		nums = append(nums[:result[0]], nums[result[1]+1:]...)
	}

	return len(nums)
}

func searchRange(nums []int, target int) []int {
	lenNums := len(nums)

	if lenNums == 0 {
		return []int{-1, -1}
	}

	if lenNums == 1 {
		if nums[0] == target {
			return []int{0, 0}
		}
		return []int{-1, -1}
	}

	if target > nums[lenNums-1] {
		return []int{-1, -1}
	}
	if target < nums[0] {
		return []int{-1, -1}
	}

	resultStart := findTheFirst(nums, target)
	if resultStart != -1 {
		resultEnd := findTheLast(nums, target)
		return []int{resultStart, resultEnd}
	} else {
		return []int{-1, -1}
	}

	return []int{-1, -1}
}

func findTheFirst(nums []int, target int) int {
	lenNums := len(nums)

	start := 0
	end := lenNums - 1

	for start < end-1 {
		if nums[start] == target && (start == 0 || nums[start-1] != target) {
			return start
		}

		middle := (end-start+1)/2 + start
		if target > nums[middle] {
			start = middle
		} else {
			end = middle
		}
	}

	if nums[start] == target && (start == 0 || nums[start-1] != target) {
		return start
	}
	if nums[end] == target && (end == 0 || nums[end-1] != target) {
		return end
	}

	return -1
}

func findTheLast(nums []int, target int) int {
	lenNums := len(nums)

	start := 0
	end := lenNums - 1

	for start < end-1 {
		if nums[end] == target && (end == lenNums-1 || nums[end+1] != target) {
			return end
		}

		middle := (end-start+1)/2 + start
		if target < nums[middle] {
			end = middle
		} else {
			start = middle
		}
	}

	if nums[end] == target && (end == lenNums-1 || nums[end+1] != target) {
		return end
	}
	if nums[start] == target && (start == lenNums-1 || nums[start+1] != target) {
		return start
	}

	return -1
}

func removeElement(nums []int, val int) int {
    for i := 0; i < len(nums); i++ {
        if nums[i] == val {
            nums = append(nums[:i], nums[i+1:]...)
            i--
        }
    }
    return len(nums)
}

func removeElement(nums []int, val int) int {
    lastIndex := len(nums) - 1
    currentIndex := 0;

    for currentIndex <= lastIndex {
        if (nums[currentIndex] == val) {
            nums[currentIndex] = nums[lastIndex]
            lastIndex--
        } else {
            currentIndex++
        }
    }

    return currentIndex;
}

*/

/** Javascript

/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */

/** Javascript

var removeElement = function(nums, val) {
    var i=0;
    for(var j=0; j<=nums.length-1; j++){
        if(nums[j]!==val){
            nums[i]=nums[j];
            i++;
        }
    }
    return i;
};

var removeElement = function(nums, val) {
    let i = 0
    while(i < nums.length) {
      let cur = nums[i]
      if (cur == val) {
        nums.splice(i,1)
      } else {
        i++
      }
    }

    return nums.length
};

var removeElement = function(nums, val) {
    var length = 0;
    nums.forEach((num, i) => {
      if (num === val) return;
      nums[length] = num;
      length++
    });
    return length;
};

var removeElement = function(nums, val) {
    let i = 0;
    let n = nums.length;
    while (i < n) {
        if (nums[i] === val) {
            nums[i] = nums[n - 1]
            n--
        } else {
            i++
        }
    }
    return n;
};

*/

/** Python

class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        iter_len = len(nums)
        count = 0
        for i in range(0, iter_len):
            if (nums[count] == val):
                nums.pop(count)
            else:
                count = count + 1

        return len(nums)

class Solution:
    def removeElement(self, A, elem):
        index = 0
        for num in A:
            if num != elem:
                A[index] = num
                index += 1
        return index

class Solution(object):
    def removeElement(self, nums, val):
        length, i = len(nums), 0
        while i < length:
            if nums[i] == val:
                nums[i] = nums[length - 1]
                length -= 1
            else:
                i += 1
        return length

*/
