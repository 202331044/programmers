# Level 2 Problems (001 ~ 030)

## Summary
- Total Solved: 30

---

## Problem List

### 1. 최댓값과 최솟값 (max_and_min)

- Time: N/A
- Solved by Myself: Yes

### 2. JadenCase 문자열 만들기 (jaden_case_string)

- Time: N/A
- Solved by Myself: Yes

### 3. 올바른 괄호 (valid_parentheses)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution:  Used `stack` to match opening and closing parentheses.
    - 2nd solution: Replaced the `stack` with a counter because only one type of parenthesis exists.

### 4. 최솟값 만들기 (make_minimum)

- Time: N/A
- Solved by Myself: Yes

### 5. 이진 변환 반복하기 (repeat_binary_conversion)

- Time: N/A
- Solved by Myself: Yes

### 6. 숫자의 표현 (number_representation)

- Time: N/A
- Solved by Myself: Yes

### 7. 다음 큰 숫자 (next_big_number)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - Applied Brian Kernighan's algorithm to count set bits.
    - Counted 1-bits in O(k), where k is the number of set bits.

### 8. 피보나치 수 (fibonacci)

- Time: N/A
- Solved by Myself: Yes

### 9. 짝지어 제거하기 (remove_pairs)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - Solved using a stack-based approach.
    - Used `string` as a lightweight stack via `push_back()` and `pop_back()`.

### 10. 카펫 (carpet)

- Time: N/A
- Solved by Myself: Yes

### 11. 귤 고르기 (tangerine_choice)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - Counted frequencies with `unordered_map`.
    - 1st solution: Kept `(count, size)` pairs.
    - 2nd solution: Removed unnecessary size information and used counts only.

### 12. 점프와 순간 이동 (jump_and_teleport)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - Counted the number of set bits in the binary representation of `n`.
    - 1st solution: Used `modulo` and `division`.
    - 2nd solution: Used `bitwise operators`.

### 13. 구명보트 (lifeboat)

- Time: N/A
- Solved by Myself: Yes

### 14. 멀리 뛰기 (long_jump)

- Time: N/A
- Solved by Myself: No
- Notes:
    - 1st solution: Tried a combinatorial approach, but handling combinations under modulo was difficult.
    - 2nd solution: Used `Fibonacci DP`.

### 15. N개의 최소공배수 (n_lcm)

- Time: N/A
- Solved by Myself: Yes

### 16. 연속 부분 수열 합의 개수 (contiguous_subsequence_sum)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
    - Refactored the solution to eliminate special handling for length 1 subsequences.
    - Used a running sum while expanding the subsequence length.

### 17. 영어 끝말잇기 (english_word_chain)

- Time: N/A
- Solved by Myself: Yes

### 18. 예상 대진표 (expected_tournament_round)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
    - Simplified the round progression logic using `(x + 1) / 2`.
    - Repeated until both players reached the same position.

### 19. 할인 행사 (discount_event)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Used a `queue` to track the discount sequence and manage product counts.
    - 2nd solution: Used a sliding window with two hash maps (`target`, `window`), resulting in cleaner code.

### 20. 괄호 회전하기 (bracket_rotation)

- Time: N/A
- Solved by Myself: Yes

### 21. n^2 배열 자르기 (n2_array_slice)

- Time: N/A
- Solved by Myself: Yes

### 22. 의상 (clothes)

- Time: N/A
- Solved by Myself: Yes

### 23. H-Index (h_index)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution:
        - Used `min(citations[i], n - i)` as an H-index candidate.
        - Tracked the maximum candidate value.
    - 2nd solution:
        - After sorting, returned the first `n - i` satisfying `citations[i] >= n - i`.

### 24. 피로도 (fatigue)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - Used DFS with backtracking to explore all possible dungeon orders.
    - Replaced the global variable with a local answer variable for better reusability.

### 25. 기능개발 (feature_development)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution:
        - Simulated deployments by updating progress values until the next deployment.
    - 2nd solution:
        - Converted progress values into completion days using ceiling division.
        - Grouped features by deployment day.

### 26. 행렬의 곱셈 (matrix_multiply)

- Time: N/A
- Solved by Myself: Yes

### 27. 전화번호 목록 (phone_number_list)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution:
        - Sort by length and check every prefix using a `hash set`.
    - 2nd solution:
        - Sort lexicographically.
        - Prefix-related phone numbers become adjacent.
        - Compare only neighboring strings.

### 28. [1차] 캐시 (cache)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution:
        - Simulated LRU using a `queue` and access timestamps stored in `unordered_map`.
        - Outdated cache records were discarded by comparing timestamps.
    - 2nd solution:
        - Implemented a real LRU cache using `list` and `unordered_map`.
        - `unordered_map` stores iterators for O(1) cache lookup.
        - `list::splice()` moves recently used entries to the front in O(1) without invalidating iterators.

### 29. 프로세스 (process)

- Time: N/A
- Solved by Myself: Yes

### 30. 롤케이크 자르기 (rollcake)

- Time: N/A
- Solved by Myself: Yes

---
