---
title: 689. 三个无重叠子数组的最大和
difficulty: 困难
date: 2023-11-19
url: https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/
tags:
    - DP
---
# [689. 三个无重叠子数组的最大和](https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/)

## 描述
给你一个整数数组 `nums` 和一个整数 `k` ，找出三个长度为 `k` 、互不重叠、且全部数字和（`3 * k` 项）最大的子数组，并返回这三个子数组。

以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 **0** 开始）。如果有多个结果，返回字典序最小的一个。

## 样例
### 示例 1：
```
输入：nums = [1,2,1,2,6,7,5,1], k = 2
输出：[0,3,5]
解释：子数组 [1, 2], [2, 6], [7, 5] 对应的起始下标为 [0, 3, 5]。
也可以取 [2, 1], 但是结果 [1, 3, 5] 在字典序上更大。
```
### 示例 2：
```
输入：nums = [1,2,1,2,1,2,1,2,1], k = 2
输出：[0,2,4]
```

## 限制
$1 \le nums.length \le 2 * 10^4$

$1 \le nums[i] < 2^{16}$

$1 \le k \le \lfloor nums.length / 3\rfloor$

## [思考](./code.cpp)
dp求从前往后和从后往前的最大区间和与区间起点，$O(N)$

枚举第二个区间的起点，$O(N)$

总体$O(N)$

## [题解](./solution.cpp)
将整个数组分为三段，同时枚举三个区间

如此可以只使用数个int来记录当前状态，空间复杂度为$O(1)$