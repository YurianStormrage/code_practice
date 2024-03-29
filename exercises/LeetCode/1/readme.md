---
title: 1. 两数之和
difficulty: 简单
date: 2023-11-20
url: https://leetcode.cn/problems/two-sum/
tags:
    - Hash
---
# [1. 两数之和](https://leetcode.cn/problems/two-sum/)

## 描述
给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** `target`  的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

## 样例
### 示例 1：
```
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```
### 示例 2：
```
输入：nums = [3,2,4], target = 6
输出：[1,2]
```
### 示例 3：
```
输入：nums = [3,3], target = 6
输出：[0,1]
```

## 限制
$2 \le nums.length \le 10^4$
$-10^9 \le nums[i] \le 10^9$
$-10^9 \le target \le 10^9$
**只会存在一个有效答案**

## 思考
考虑到数字范围大而 n <= 1e4，可以将数字离散化再用桶存

等价于直接将元素映射到序号。使用哈希映射性能更好。

## 题解
不需要预处理出映射，直接在枚举求解过程中将枚举过的元素添加到映射中。常数优化。