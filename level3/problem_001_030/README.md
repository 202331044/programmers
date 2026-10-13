# Level 3 Problems

## Summary
- Total Solved: 15

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

### 6. 등굣길 (way_to_school)

- Time: N/A
- Solved by Myself: Yes

### 7. 숫자 게임 (number_game)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution:
		- Sorted arrays in descending order using `rbegin()` and `rend()`.
		- Used four pointers to compare numbers.
	- 2nd solution:
		- Sorted arrays in ascending order.
		- Used two pointers with a greedy approach.

### 8. 단속카메라 (speed_camera)

- Time: N/A
- Solved by Myself: Yes

### 9. 기지국 설치 (base_station_installation)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution:
		- Moved the current position by the coverage length.
		- Skipped the covered area when encountering an existing station.
	- 2nd solution:
		- Calculated the length of uncovered sections.
		- Calculated the required number of stations using the coverage length.

### 10. 최고의 집합 (best_set)

- Time: N/A
- Solved by Myself: Yes

### 11. 베스트앨범 (best_album)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
	- 1st Solution: Used `pair<int, int>` to store song IDs and play counts.
	- 2nd Solution: Introduced a `Song` struct for better readability.
	- Both use the same algorithm, selecting up to two songs per genre based on play counts and song IDs.

### 12. 불량 사용자 (banned_user)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st Solution: Mapped user IDs to indices and tracked selections using `vector<bool>`.
	- 2nd Solution: Used `bitmasking` to track selected users and `unordered_set` to deduplicate cases.
	- Both solutions use `DFS` to explore valid banned-user combinations and prevent selecting the same user more than once.

### 13. 보석 쇼핑 (gem_shopping)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st Solution: Manually controlled both pointers to expand and shrink the window while tracking gem counts.
	- 2nd Solution: Used a frequency map to shrink the window whenever all gem types were included, updating the shortest valid range.

### 14. 부대복귀 (return_to_military_base)

- Time: N/A
- Solved by Myself: Yes
- Notes: Used `BFS` from the destination to calculate the shortest distance to every region.

### 15. 섬 연결하기 (connecting_islands)

- Time: N/A
- Solved by Myself: No
- Notes:
	- The initial solution failed because edges were not added in both directions when building the graph.
	- Solution:
		- Built an undirected graph by adding each edge in both directions.
		- Used `Prim's algorithm` with a `min-priority queue` to select the lowest-cost edges.
		- Added the cost of each selected edge and marked the newly connected island as visited.

---
