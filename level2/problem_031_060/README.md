# Level 2 Problems (031 ~ 060)

## Summary
- Total Solved: 10

---

## Problem List

### 31. 게임 맵 최단거리 (game_map_shortest_path)

- Time: N/A
- Solved by Myself: Yes

### 32. 타겟 넘버 (target_number)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Used `DFS` to explore all possible combinations of + and -.
	- 2nd solution: 
		- Used `dynamic programming`. `dp[s]` represents the number of ways to make a sum `s`.
		- Since sums can be negative, an offset (+1000) was used to map the range [-1000, 1000] to array indices.
	- Time Complexity:
		- DFS: O(2^N)
		- DP: O(N × 2001)

### 33. 튜플 (tuple)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
	- 1st solution: 
		- Parsed the string into a 2D integer array. 
		- Sorted subsets by size and identified the newly added element using `unordered_set`. 
	- 2nd solution:
		- Counted the frequency of each number using `unordered_map`.
		- Reconstructed the tuple by sorting numbers in descending order of frequency.

### 34. 모음사전 (vowel_dictionary)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Used `DFS` to generate words in lexicographical order and count their positions.
	- 2nd solution: Used positional weights to compute the order directly without generating all words.

### 35. 방문 길이 (path_length)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution:  Used a 4D array to track visited edges.
	- 2nd solution:
		- Used a `set<Edge>` to store unique edges.
  		- Normalized bidirectional edges and returned `set::size()`.

### 36. [1차] 뉴스 클러스터링 (news_clustering)

- Time: N/A
- Solved by Myself: Yes

### 37. 뒤에 있는 큰 수 찾기 (next_greater_number)

- Time: N/A
- Solved by Myself: Yes
- Notes: Optimized stack storage by keeping only indices instead of `pair<value, index>`, since values can be accessed through `numbers[idx]`.

### 38. 더 맵게 (more_spicy)

- Time: N/A
- Solved by Myself: Yes

### 39. k진수에서 소수 개수 구하기 (prime_count_k_base)

- Time: N/A
- Solved by Myself: No
- Notes:
    - Initial solution timed out due to inefficient prime checking.
    - Optimized prime checking to O(√N).
    - Skipped even divisors after handling `num % 2 == 0`..

### 40. 주식가격 (stock_price)

- Time: N/A
- Solved by Myself: Yes

---
