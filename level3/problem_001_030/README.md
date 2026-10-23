# Level 3 Problems

## Summary
- Total Solved: 25

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

### 16. 여행경로 (travel_route)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: 
		- Explored all possible routes using `DFS` and `backtracking`.
		- Returned the first valid route in lexicographical order.
	- 2nd solution: 
		- Used `Hierholzer's algorithm` to construct an `Eulerian path`.
		- Used a `min-heap priority queue` to explore destinations in lexicographical order.
		- Added airports to the route after exploring all outgoing tickets, then reversed the resulting route.

### 17. 가장 먼 노드 (farthest_node)

- Time: N/A
- Solved by Myself: Yes
- Notes: Separated the maximum distance calculation from the `BFS` traversal, which calculates the distance to each node.

### 18. 징검다리 건너기 (stepping_stones)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution:
		- Used a `min-heap priority queue` to process stones in ascending order of their durability.
		- Tracked consecutive unusable stones and returned the number of people who could cross when the count reached `k`.
	- 2nd solution:
		- Used `binary search` to find the maximum number of people who could cross.
		- If `k` consecutive stones could not support `mid` people, reduced the upper bound; otherwise, increased the lower bound.

### 19. 연속 펄스 부분 수열의 합 (consecutive_pulse_subsequence_sum)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution:
		- Used two separate loops to evaluate both alternating pulse patterns.
		- Reset the cumulative sum to 0 whenever it became negative.
	- 2nd solution:
		- Evaluated both alternating pulse patterns simultaneously in a single loop.
		- Updated both cumulative sums at each index and tracked the maximum sum.

### 20. 스티커 모으기(2) (collecting_stickers_2)

- Time: N/A
- Solved by Myself: No
- Notes:
	- The initial solution failed to handle the cases of selecting the first or last sticker separately.
	- Solution:
		- Used `dynamic programming` and divided the problem into two cases: selecting the first sticker or excluding it.
		- Used the recurrence relation `dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i])` to calculate the maximum sum.

### 21. 입국심사 (immigration_inspection)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
	- Optimized binary search by setting the upper bound to `n * times[0]`.
	- Terminated the loop early when the processed count reached `n`.

### 22. 디스크 컨트롤러 (disk_controller)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
	- 1st solution: Used two `min-heaps` to manage jobs by arrival time and processing time, respectively.
	- 2nd solution: Sorted jobs by arrival time in advance and used a single `min-heap` to prioritize available jobs by processing time.

### 23. 가장 긴 팰린드롬 (longest_palindrome)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
	- 1st solution: 
		- Checked substrings for palindromes and updated the maximum length. 
		- Started checking from `maxLen + 1` to skip shorter substrings.
	- 2nd solution: 
		- Used the `expand-around-center approach`, expanding left and right from each center for both odd- and even-length palindromes.
		- Reduced the time complexity from `O(N³)` to `O(N²)` and the auxiliary space complexity from `O(N)` to `O(1)`.

### 24. 경주로 건설 (race_track_construction)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
	- Used `Dijkstra's algorithm` with a `min-priority queue` to process states in increasing order of construction cost.
	- Tracked visited states by position and direction to account for different costs of reaching the same cell.

### 25. 다단계 칫솔 판매 (multi_level_toothbrush_sales)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution:
		- Stored sales counts for each possible price and processed each person's earnings by iterating through all possible prices.
		- Passed the referral commission to the parent by updating the parent's price counts.
	- 2nd solution:
		- Used a parent array to store each person's referrer index and an `unordered_map` to map names to indices.
		- Processed each sale individually, distributing 10% of the remaining money up the referral chain until the money became 0 or there was no referrer.
		- Improved space efficiency from `O(N * M)` to `O(N)`, where `N` is the number of members and `M` is the number of possible prices.

---
