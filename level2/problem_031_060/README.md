# Level 2 Problems (031 ~ 060)

## Summary
- Total Solved: 25

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

### 41. 땅따먹기 (land_game)

- Time: N/A
- Solved by Myself: Yes

### 42. [3차] 압축 (compression)

- Time: N/A
- Solved by Myself: Yes

### 43. [3차] n진수 게임 (base_n_game)

- Time: N/A
- Solved by Myself: Yes
- Notes:
  - 1st solution: Generated the entire sequence first, then extracted the characters for the player's turns.
  - 2nd solution: Generated only the required characters on the fly, avoiding the need to store the entire sequence.

### 44. 택배상자 (delivery_box)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Processed the delivery order using sorting.
	- 2nd solution: Simulated the delivery process using a `stack`.

### 45. 숫자 변환하기 (convert_number)

- Time: N/A
- Solved by Myself: No
- Notes:
  - 1st solution: Tried `DFS`, but it exceeded the time limit due to exploring too many states.
  - 2nd solution: Solved the problem using `BFS` to find the minimum number of operations.
  - 3rd solution: Solved the problem using `DP` by exploiting the fact that every operation only increases the value.

### 46. 스킬트리 (skill_tree)

- Time: N/A
- Solved by Myself: Yes
- Notes:
  - 1st solution: Iterated over the required skills and located them in each skill tree using `find()`.
  - 2nd solution: Iterated over each skill tree once while tracking the next expected skill.

### 47. 주차 요금 계산 (parking_fee)

- Time: N/A
- Solved by Myself: Yes

### 48. 2 x n 타일링 (2_n_tiling)

- Time: N/A
- Solved by Myself: Yes

### 49. [3차] 파일명 정렬 (file_name_sort)

- Time: N/A
- Solved by Myself: Yes
- Notes:
  - 1st solution: Parsed each file into a `Name` structure and preserved the original order by storing the original indices.
  - 2nd solution:
    - Used a `FileInfo` structure containing both the original file name and the parsed information.
    - Used `stable_sort` to preserve the original order of equivalent elements.

### 50. 오픈채팅방 (open_chat_room)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Parsed each record twice to update nicknames and generate messages.
	- 2nd solution: Parsed each record once, stored the events, and reused them to generate the final messages.

### 51. [1차] 프렌즈4블록 (friends_4block)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
	- Simplified the 2×2 block detection using direct condition comparisons.
	- Refactored the gravity logic to eliminate unnecessary swaps and improve readability.

### 52. 가장 큰 수 (largest_number)

- Time: N/A
- Solved by Myself: No
- Notes:
	- 1st attempt: Converted the numbers to strings and compared them digit by digit, which failed for some cases.
	- Solution: Sorted the strings by comparing `a + b` and `b + a`.

### 53. 소수 찾기 (find_primes)

- Time: N/A
- Solved by Myself: Yes
- Notes: Improved the DFS by skipping duplicate permutations when identical digits had not been used previously.

### 54. 2개 이하로 다른 비트 (two_different_bits)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution:
		- Converted numbers to binary strings.
		- Replaced the first `0` with `1` and the preceding bit with `0`.
	- 2nd solution:
		- Used `number ^ (number + 1)` to identify the bit pattern.
		- Calculated the increment as `(k >> 2) + 1`, where `k = number ^ (number + 1)`.

### 55. 쿼드압축 후 개수 세기 (compress_quad)

- Time: N/A
- Solved by Myself: Yes

---
