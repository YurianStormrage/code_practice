---
title: 规划兼职工作
difficulty: Hard
date: 2024-05-06 05:01:18
url: https://leetcode.cn/problems/maximum-profit-in-job-scheduling
tags:
    - DP
    - Binary Search
---
# 1235. 规划兼职工作

## 描述

你打算利用空闲时间来做兼职工作赚些零花钱。

这里有 `n` 份兼职工作，每份工作预计从 `startTime[i]` 开始到 `endTime[i]` 结束，报酬为 `profit[i]`。

给你一份兼职工作表，包含开始时间 `startTime`，结束时间 `endTime` 和预计报酬 `profit` 三个数组，请你计算并返回可以获得的最大报酬。

注意，时间上出现重叠的 2 份工作不能同时进行。

如果你选择的工作在时间 `X` 结束，那么你可以立刻进行在时间 `X` 开始的下一份工作。

## 样例

### 示例 1

**<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/19/sample1_1584.png" style="width: 300px;">**

```
输入：startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
输出：120
解释：
我们选出第 1 份和第 4 份工作， 
时间范围是 [1-3]+[3-6]，共获得报酬 120 = 50 + 70。
```

### 示例 2

**<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/19/sample22_1584.png" style="height: 112px; width: 600px;">** 

```
输入：startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
输出：150
解释：
我们选择第 1，4，5 份工作。 
共获得报酬 150 = 20 + 70 + 60。
```

### 示例 3

**<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/19/sample3_1584.png" style="height: 112px; width: 400px;">**

```
输入：startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
输出：6
```

## 限制

- `1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4`
- `1 <= startTime[i] < endTime[i] <= 10^9`
- `1 <= profit[i] <= 10^4`


## [思考](code.cpp)
做的时候没想太多，直接离散化+DP暴力过了。
但是常数略大。

具体的，离散化所有区间的左右端点，对离散后的时刻DP。

对于时刻 i，取右端点为 i 的区间与其左端点之前的答案的和，更新答案。

## [题解](solution.cpp)
DP+二分优化。

不对时刻DP，而是排序后对前 i 个区间DP。

转移时，二分查找第 i 个区间的左端点之前的最后一个区间 j ，用区间 i 与答案 j 更新。
