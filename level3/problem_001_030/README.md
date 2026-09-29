# Level 3 Problems

## Summary
- Total Solved: 5

---

## Problem List

### 1. 단어 변환 (word_transformation)

- Time: N/A
- Solved by Myself: Yes

### 2. 네트워크 (network)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- Counted connected components by traversing unvisited computers.
	- 1st solution: Used `bfs`.
	- 2nd solution: Used `dfs`.

### 3. 정수 삼각형 (integer_triangle)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Used separate `pre` and `post` arrays to calculate maximum cumulative sums.
	- 2nd solution: Reused the original array to calculate maximum cumulative sums, reducing auxiliary space from `O(N)` to `O(1)`.

### 4. 야근 지수 (overtime_index)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution:
		- Used a frequency array to count the number of works for each workload.
		- Reduced workloads from the highest value while considering `n`.
	- 2nd solution: Used `priority_queue` to reduce the largest workload iteratively.

### 5. 이중우선순위큐 (double_priority_queue)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Used min/max `priority_queue`s with additional queues for lazy deletion.
	- 2nd solution: Used `multiset` to handle both minimum and maximum values.

---
