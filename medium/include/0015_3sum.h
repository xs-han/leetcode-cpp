//
// Created by xushen on 2/1/20.
//

#ifndef LEETCODE_CPP_0015_3SUM_H
#define LEETCODE_CPP_0015_3SUM_H

#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Q_0015 {

class Solution {
 public:
    class VectorHash {
     public:
        size_t operator()(const std::vector<int>& r) const {
            return std::hash<int>()(r[0]) ^
                   std::hash<int>()(r[1]) ^
                   std::hash<int>()(r[2]);
        }
    };
    class VectorEqual {
     public:
        bool operator()(const std::vector<int>& r1, const std::vector<int>& r2) const {
            return r1[0] == r2[0] &&
                   r1[1] == r2[1] &&
                   r1[2] == r2[2];
        }
    };
    std::vector<std::vector<int>> threeSum(const std::vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::unordered_map<int, int> map_numbers;
        std::unordered_set<std::vector<int>, VectorHash, VectorEqual> map_results;

        for (int n : nums) {
            if (map_numbers.count(n)) {
                map_numbers[n] += 1;
            } else {
                map_numbers.insert(std::make_pair(n, 1));
            }
        }

        std::vector<std::vector<int>> results;
        std::vector<int> sum_elems(3);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                sum_elems[0] = nums[i];
                sum_elems[1] = nums[j];
                sum_elems[2] = -sum_elems[0]-sum_elems[1];
                map_numbers[nums[i]]--;
                map_numbers[nums[j]]--;
                if (map_numbers[sum_elems[2]] > 0) {
                    if (sum_elems[0] > sum_elems[1]) {
                        std::swap(sum_elems[0], sum_elems[1]);
                    }
                    if (sum_elems[1] > sum_elems[2]) {
                        std::swap(sum_elems[1], sum_elems[2]);
                    }
                    if (sum_elems[0] > sum_elems[1]) {
                        std::swap(sum_elems[0], sum_elems[1]);
                    }
                    if (!map_results.count(sum_elems)) {
                        map_results.insert(sum_elems);
                        results.emplace_back(sum_elems);
                    }
                }
                map_numbers[nums[i]]++;
                map_numbers[nums[j]]++;
            }
        }
        return results;
    }
};

class Solution2 {
 public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::vector<std::vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }

        std::unordered_map<int, int> map_numbers;
        for (int n : nums) {
            if (map_numbers.count(n)) {
                map_numbers[n] += 1;
            } else {
                map_numbers.insert(std::make_pair(n, 1));
            }
        }
        if (map_numbers.count(0) && map_numbers[0] >= 3) {
            result.push_back({0, 0, 0});
        }

        std::sort(nums.begin(), nums.end());
        if (nums[0] >= 0 || nums[nums.size() - 1] <= 0) {
            return result;
        }

        auto p_zero_begin = std::lower_bound(nums.begin(), nums.end(), -1);
        auto p_zero_end = p_zero_begin;
        for (;*p_zero_end <= 0; p_zero_end++);

        std::vector<int> tmp_r(3);
        int previous_p1 = INT32_MIN;
        for (auto p1 = nums.begin(); p1 <= p_zero_begin; p1++) {
            if (*p1 == previous_p1) {
                continue;
            }
            int previous_p2 = INT32_MIN;
            for (auto p2 = p_zero_end; p2 < nums.end(); p2++) {
                if (*p2 == previous_p2) {
                    continue;
                }
                tmp_r[0] = *p1;
                tmp_r[1] = *p2;
                tmp_r[2] = -(*p1)-(*p2);
                if (tmp_r[2] < tmp_r[0] || tmp_r[2] > tmp_r[1]) {
                    continue;
                }
                map_numbers[tmp_r[0]]--;
                map_numbers[tmp_r[1]]--;
                if (map_numbers[tmp_r[2]]) {
                    result.emplace_back(tmp_r);
                }
                map_numbers[tmp_r[0]]++;
                map_numbers[tmp_r[1]]++;
                previous_p2 = *p2;
            }
            previous_p1 = *p1;
        }
        return result;
    }
};

class Solution3 {
 public:
    std::vector<std::vector<int> > threeSum(std::vector<int> &nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::vector<std::vector<int> > res;

        std::sort(nums.begin(), nums.end());
        std::vector<int> triplet(3, 0);
        for (auto p_target = nums.begin(); p_target != nums.end(); p_target++) {

            int target = -(*p_target);
            auto p_front = p_target + 1;
            auto p_back = nums.end() - 1;

            while (p_front < p_back) {

                int sum = *p_front + *p_back;

                // Finding answer which start from number num[i]
                if (sum < target)
                    p_front++;

                else if (sum > target)
                    p_back--;

                else {
                    triplet[0] = *p_target;
                    triplet[1] = *p_front;
                    triplet[2] = *p_back;
                    res.push_back(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (p_front < p_back && *p_front == triplet[1]) p_front++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (p_front < p_back && *p_back == triplet[2]) p_back--;
                }

            }

            // Processing duplicates of Number 1
            while (p_target+1 < nums.end() && *(p_target+1) == *p_target)
                p_target++;
        }
        return res;
    }
};

}

#endif //LEETCODE_CPP_0015_3SUM_H
