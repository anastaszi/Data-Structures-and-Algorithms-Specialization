# Problems:

## 1. Binary Search

**Task**: The goal in this code problem is to implement the binary search algorithm.\
**Input**: The first line of the input contains an integer 𝑛 and a sequence 𝑎0 < 𝑎1 < . . . < 𝑎𝑛−1 of 𝑛 pairwise distinct positive integers in increasing order. The next line contains an integer 𝑘 and 𝑘 positive integers 𝑏0, 𝑏1, . . . , 𝑏𝑘−1.\
**Constraints**: 1≤𝑛,𝑘≤10^4;1≤𝑎𝑖 ≤10^9 for all 0≤𝑖<𝑛; 1≤𝑏𝑗 ≤10^9 for all 0≤𝑗<𝑘;\
**Output**: For all 𝑖 from 0 to 𝑘−1,output an index 0≤𝑗≤𝑛−1 such that 𝑎𝑗 =𝑏𝑖 or −1 if there is no such index..

## 2. Majority Element

**Task**: The goal in this code problem is to check whether an input sequence contains a majority element.\
**Input**: The first line contains an integer 𝑛, the next one contains a sequence of 𝑛 non-negative
integers 𝑎0, 𝑎1, . . . , 𝑎𝑛−1.\
**Constraints**: 1≤𝑛≤10^5; 0≤𝑎𝑖 ≤10^9 for all 0≤𝑖<𝑛.\
**Output**: Output 1 if the sequence contains an element that appears strictly more than 𝑛/2 times, and 0 otherwise.

## 3. Improving Quick Sort

**Task**: To force the given implementation of the quick sort algorithm to efficiently process sequences with few unique elements, your goal is replace a 2-way partition with a 3-way partition. That is, your new partition procedure should partition the array into three parts: < 𝑥 part, = 𝑥 part, and > 𝑥 part.\
**Input**: The first line of the input contains an integer 𝑛. The next line contains a sequence of 𝑛 integers 𝑎0, 𝑎1, . . . , 𝑎𝑛−1.\
**Constraints**: 1≤𝑛≤10^5; 1 ≤𝑎𝑖 ≤10^9 for all 0≤𝑖<𝑛.\
**Output**: Output this sequence sorted in non-decreasing order.

## 4. Number of Inversions
An inversion of a sequence 𝑎0,𝑎1,...,𝑎𝑛−1 is a pair of indices 0 ≤ 𝑖 < 𝑗 < 𝑛 such that 𝑎𝑖 > 𝑎𝑗. The number of inversions of a sequence in some sense measures how close the sequence is to being sorted. For example, a sorted (in non-descending order) sequence contains no inversions at all, while in a sequence sorted in de- scending order any two elements constitute an inversion (for a total of 𝑛(𝑛 − 1)/2 inversions).
**Task**: The goal in this problem is to count the number of inversions of a given sequence.\
**Input**: The first line contains an integer 𝑛, the next one contains a sequence of integers 𝑎0, 𝑎1, ..., 𝑎𝑛−1.\
**Constraints**: 1≤𝑛≤10^5; 1 ≤𝑎𝑖 ≤10^9 for all 0≤𝑖<𝑛.\
**Output**: Output the number of inversions in the sequence.

## 5. Organizing a Lottery

**Task**: You are given a set of points on a line and a set of segments on a line. The goal is to compute, for each point, the number of segments that contain this point.\
**Input**: The first line contains two non-negative integers 𝑠 and 𝑝 defining the number of segments and the number of points on a line, respectively. The next 𝑠 lines contain two integers 𝑎𝑖,𝑏𝑖 defining the 𝑖-th segment [𝑎𝑖, 𝑏𝑖]. The next line contains 𝑝 integers defining points 𝑥1, 𝑥2, . . . , 𝑥𝑝.\
**Constraints**: 1≤ 𝑠,𝑝≤ 50000; −10^8 ≤𝑎𝑖 ≤𝑏𝑖 ≤10^8 for all 0≤𝑖<𝑠; −10^8 ≤𝑥𝑗 ≤10^8 for all 0≤𝑗<𝑝\
**Output**: Output 𝑝 non-negative integers 𝑘0, 𝑘1, . . . , 𝑘𝑝−1 where 𝑘𝑖 is the number of segments which contain 𝑥𝑖.

## 6. Closest Points

**Task**: Given 𝑛 points on a plane, find the smallest distance between a pair of two (different) points.\
**Input**: The first line contains the number 𝑛 of points. Each of the following 𝑛 lines defines a point (𝑥𝑖, 𝑦𝑖).\
**Constraints**: 2 ≤ 𝑛 ≤ 10^5 ; −10^9 ≤ 𝑥𝑖 , 𝑦𝑖 ≤ 10^9 are integers.\
**Output**: Output the minimum distance. The absolute value of the difference between the answer of your program and the optimal value should be at most 10^-3. To ensure this, output your answer with at least four digits after the decimal point (otherwise your answer, while being computed correctly, can turn out to be wrong because of rounding issues).
