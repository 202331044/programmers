# Level 2 Problems (001 ~ 030)

## Summary
- Total Solved: 20

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

---
