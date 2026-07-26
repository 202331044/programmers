# Level 2 Problems (061 ~ 090)

## Summary
- Total Solved: 10

---

## Problem List

### 61. 연속된 부분 수열의 합 (contiguous_subsequence_sum)

- Time: N/A
- Solved by Myself: Yes
- Notes: Refactored variable names and simplified the two-pointer implementation.

### 62. 삼각 달팽이 (triangle_snail)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Used separate loops for each direction.
	- 2nd solution: Simplified the implementation by using direction arrays (`dr`, `dc`) and boundary checks.

### 63. 시소 짝꿍 (seesaw_pairs)

- Time: N/A
- Solved by Myself: No
- Notes:
    - 1st attempt: Failed because I compared weights directly in addition to comparing `weight × distance`.
    - 1st solution: Calculated the torque (`weight × distance`) for each possible distance and compared them one by one.
    - 2nd solution: Used a frequency map to count pairs that satisfy the valid balance ratios.

### 64. 숫자 카드 나누기 (number_card_division)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Iterated through all possible divisors after computing the GCD.
    - 2nd solution: Verified only the GCD instead of checking every divisor, since every valid divisor is a divisor of the GCD.

### 65. 호텔 대실 (hotel_booking)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Counted the maximum number of overlapping bookings using a line sweep.
    - 2nd solution: Used a min-heap (`priority_queue`) to track the earliest available room.

### 66. 배달 (delivery)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution:
        - Used an adjacency matrix with a BFS-like traversal.
        - Updated the shortest distance whenever a shorter path was found.
        - Inefficient because it checked every vertex for each node.
    - 2nd solution:
        - Switched from an adjacency matrix to an adjacency list.
        - Applied Dijkstra's algorithm using a priority queue.
        - Improved efficiency by traversing only adjacent nodes.

### 67. 서버 증설 횟수 (server_expansion_count)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Used a queue to manage active servers and their expiration times.
    - 2nd solution:
        - Replaced the queue with a vector indexed by expiration time.
        - Simplified expiration handling with direct indexing.

### 68. 리코쳇 로봇 (ricochet_robot)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Used a separate `visited` array and stored the move count in the BFS queue.
    - 2nd solution:
        - Extracted the logic for finding the start position into a helper function.
        - Replaced the `visited` array with a `dist` array to track both visited states and move counts.

### 69. 메뉴 리뉴얼 (menu_renewal)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Generated all possible menu combinations and stored them by size.
    - 2nd solution: Generated only combinations of the target sizes.

### 70. 124 나라의 숫자 (124_country_number)

- Time: N/A
- Solved by Myself: No
- Notes:
    - Attempt: Tried converting the number using `% 3`, but failed because the 124 number system has no digit `0`.
    - Solution:
        - If `n % 3 == 0`, append `4` instead of `0`.
        - Decrease the quotient by `1` (`n = n / 3 - 1`) because replacing `0` with `4` borrows `1` from the next higher digit.

---
