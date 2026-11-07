# Level 3 Problems

## Summary
- Total Solved: 5

---

## Problem List

### 31. 거스름돈 (change)

- Time: N/A
- Solved by Myself: No
- Notes: 
	- 1st attempt: Tried to solve using `dynamic programming`, but failed to handle duplicate combinations.
	- Solution:
		- Used `dynamic programming` by iterating through each coin denomination first.
		- For each coin, updated the DP array from the current coin value to n.
		- This ensures that each combination is counted only once, avoiding duplicate counting.

### 32. 파괴되지 않은 건물 (undestroyed_buildings)

- Time: N/A
- Solved by Myself: No
- Notes: 
	- 1st attempt: Tried to apply each skill directly to the board, but exceeded the time limit.
	- Solution:
		- Used a `2D difference array` to efficiently record range updates.
		- Applied `2D prefix sums` to calculate the actual damage or recovery for each cell.
		- Avoided updating individual cells repeatedly, improving time complexity.

### 33. 자물쇠와 열쇠 (lock_and_key)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
	- 1st solution:
		- Used arrays to store lock holes and key bumps.
		- Aligned the first lock hole with each key bump, based on the idea that every hole must be covered by at least one key bump.
		- Rotated the key 90 degrees each time to check all four orientations.
	- 2nd solution:
		- Used a padded board to allow the key to move beyond the lock boundaries.
		- Applied the key to the board and checked whether the lock was fully unlocked.
		- Reverted the changes after each attempt to test the next position.
		- Rotated the key 90 degrees clockwise using the formula: `new_key[x][m - y - 1] = key[y][x]`.

### 34. 표 편집 (table_edit)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
	- 1st solution:
		- Used two `priority queues` (left and right) to manage valid rows before and after the current position.
		- Used a `stack` to restore deleted rows in reverse order.
	- 2nd solution:
		- Used an `array-based doubly linked list` with pre and next arrays.
		- Updated neighboring nodes' links to delete or restore rows in `O(1)`.

### 35. 양과 늑대 (sheep_and_wolves)

- Time: N/A
- Solved by Myself: No
- Notes:
	- 1st attempt: Tried using a `priority_queue` to maximize the number of sheep, but failed to consider all possible routes.
	- 1st solution: 
		- Used `dfs` with an available array to track nodes that could be visited.
		- Explored all available nodes and created a new available array after visiting each node.
		- Pruned routes where the number of wolves would become greater than or equal to the number of sheep.
	- 2nd solution:
		- Used `bitmask` to represent the visited nodes.
		- Used a visited_state array to avoid exploring duplicate visited states.
		- Stored parent information to check whether a node could be visited.

---