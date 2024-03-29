---
title: 53. 最大子数组和
difficulty: 中等
date: 2023-11-20
url: https://leetcode.cn/problems/maximum-subarray/
tags:
    - DP
---
# [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/)

## 描述
给你一个整数数组 `nums` ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

**子数组** 是数组中的一个连续部分。

## 样例
### 示例 1：
```
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```
### 示例 2：
```
输入：nums = [1]
输出：1
```
### 示例 3：
```
输入：nums = [5,4,-1,7,8]
输出：23
```

## 限制
$1 \le nums.length \le 10^5$

$-10^4 \le nums[i] \le 10^4$

## 思考
最大子序列和模板

ans记录最大和

now记录当前子序列和，当now < 0时令now = 0。等价于放弃当前序列，重新开始统计。

注意不能用赋值的 0 更新 ans