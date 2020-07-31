# Problems:

## 1. Money Change

**Task**: he goal in this problem is to find the minimum number of coins needed to change the input value (an integer) into coins with denominations 1, 5, and 10.\
**Input**: The input consists of a single integer 𝑚.\
**Constraints**: 1 ≤ 𝑚 ≤ 10^3.\
**Output**: Output the minimum number of coins with denominations 1, 5, 10 that changes 𝑚.


## 2. Maximum Value of the Loot

**Task**: The goal of this code problem is to implement an algorithm for the fractional knapsack problem.\
**Input**: The first line of the input contains the number 𝑛 of items and the capacity 𝑊 of a knapsack. The next 𝑛 lines define the values and weights of the items. The 𝑖-th line contains integers 𝑣𝑖 and 𝑤𝑖—the value and the weight of 𝑖-th item, respectively.\
**Constraints**: 1≤𝑛≤10^3,0≤𝑊 ≤2·10^6;0≤𝑣𝑖 ≤2·10^6,0<𝑤𝑖 ≤2·10^6 for all 1≤𝑖≤𝑛. All the numbers are integers.\
**Output**: Output the maximal value of fractions of items that fit into the knapsack. The absolute value of the difference between the answer of your program and the optimal value should be at most 10^-3.

## 3. Car Fueling

**Task**: Assuming that the distance between the cities is 𝑑 miles, a car can travel at most 𝑚 miles on a full tank, and there are gas stations at distances stop1 , stop2 , . . . , stop𝑛 along the way, output the minimum number of refills needed. Assume that the car starts with a full tank. If it is not possible to reach the destination, output −1.\
**Input**:
The first line contains an integer 𝑑. The second line contains an integer 𝑚. The third line specifies an integer 𝑛. Finally, the last line contains integers stop1, stop2, . . . , stop𝑛.\
**Constraints**: 1≤𝑑≤10^5. 1≤𝑚≤400. 1≤𝑛≤300. 0 < stop1 < stop2 <···<stop𝑛 <𝑑 .\
**Output**: Output the number of refills.

## 4. Maximum Advertisement Revenue

**Task**: Given two sequences 𝑎1,𝑎2,...,𝑎𝑛 (𝑎𝑖 is the profit per click of the 𝑖-th ad) and 𝑏1,𝑏2,...,𝑏𝑛 (𝑏𝑖 is the average number of clicks per day of the 𝑖-th slot), we need to partition them into 𝑛 pairs (𝑎𝑖,𝑏𝑗) such that the sum of their products is maximized.\
**Input**: The first line contains an integer 𝑛, the second one contains a sequence of integers 𝑎1,𝑎2,...,𝑎𝑛, the third one contains a sequence of integers 𝑏1,𝑏2,...,𝑏𝑛.\
**Constraints**: 1≤𝑛≤10^3;−10^5 ≤𝑎𝑖,𝑏𝑖 ≤10^5 for all 1≤𝑖≤𝑛.\
**Output**: Output the maximum value of ∑︀ 𝑎𝑖𝑐𝑖, where 𝑐1, 𝑐2, . . . , 𝑐𝑛 is a permutation of
 𝑏1,𝑏2,...,𝑏𝑛.

## 5. Collecting Signatures
**Task**: Given a set of 𝑛 segments {[𝑎0,𝑏0],[𝑎1,𝑏1],...,[𝑎𝑛−1,𝑏𝑛−1]} with integer coordinates on a line, find the minimum number 𝑚 of points such that each segment contains at least one point. That is, find a set of integers 𝑋 of the minimum size such that for any segment [𝑎𝑖,𝑏𝑖] there is a point 𝑥 ∈ 𝑋 such that𝑎𝑖 ≤𝑥≤𝑏𝑖.\
**Input**: The first line of the input contains the number 𝑛 of segments. Each of the following 𝑛 lines contains two integers 𝑎𝑖 and 𝑏𝑖 (separated by a space) defining the coordinates of endpoints of the 𝑖-th segment.\
**Constraints**: 1≤𝑛≤100; 0≤𝑎𝑖 ≤𝑏𝑖 ≤10^9 for all 0≤𝑖<𝑛.\
**Output**: Output the minimum number 𝑚 of points on the first line and the integer coordinates of 𝑚 points (separated by spaces) on the second line. You can output the points in any order. If there are many such sets of points, you can output any set. (It is not difficult to see that there always exist a set of points of the minimum size such that all the coordinates of the points are integers.)


## 6. Maximum Number of Prizes

**Task**: The goal of this problem is to represent a given positive integer 𝑛 as a sum of as many pairwise distinct positive integers as possible. That is, to find the maximum 𝑘 such that 𝑛 can be written as 𝑎1+𝑎2+···+𝑎𝑘 where𝑎1,...,𝑎𝑘 are positive integers and 𝑎𝑖 ̸=𝑎𝑗, for all 1≤𝑖<𝑗≤𝑘.\
**Input**: The input consists of a single integer 𝑛.\
**Constraints**: 0 ≤ 𝑛 ≤ 10^9 .\
**Output**: In the first line, output the maximum number 𝑘 such that 𝑛 can be represented as a sum of 𝑘 pairwise distinct positive integers. In the second line, output 𝑘 pairwise distinct positive integers that sum up to 𝑛 (if there are many such representations, output any of them).

## 7. Maximum Salary

**Task**: Compose the largest number out of a set of integers.\
**Input**: The first line of the input contains an integer 𝑛. The second line contains integers
𝑎1,𝑎2,...,𝑎𝑛.\
**Constraints**: 1≤𝑛≤100;1≤𝑎𝑖 ≤10^3 for all 1 ≤𝑖 ≤𝑛.\
**Output**:  Output the largest number that can be composed out of 𝑎1, 𝑎2, . . . , 𝑎𝑛.
