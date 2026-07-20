# Level 2 Problems (061 ~ 090)

## Summary
- Total Solved: 5

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

---
