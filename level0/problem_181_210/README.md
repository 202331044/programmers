# Level 0 Problems (181 ~ 210)

## Summary
- Total Solved: 12

---

## Problem List

### 181. 배열 만들기 4 (make_array_4)

- Time: N/A
- Solved by Myself: Yes

### 182. 조건 문자열 (conditional_string)

- Time: N/A
- Solved by Myself: Yes

### 183. [PCCE 기출문제] 5번 / 산책 (pcce_5_stroll)

- Time: N/A
- Solved by Myself: Yes
- Notes: Fill-in-the-blank problem.

### 184. 공 던지기 (ball_passing)

- Time: N/A
- Solved by Myself: No
- Notes:
    - 1st solution: Missed edge case when `k % order.size() == 0`.
    - 2nd solution: Moved index by 2 each turn using modulo to simulate circular behavior `(2 * (k - 1)) % n`.

### 185. 문자열 계산하기 (string_calculation)

- Time: N/A
- Solved by Myself: Yes
- Notes: Simplified from token parsing to structured stringstream parsing.

### 186. 두 수의 합 (sum_of_two_numbers)

- Time: N/A
- Solved by Myself: Yes

### 187. 수열과 구간 쿼리 2 (sequence_and_query_2)

- Time: N/A
- Solved by Myself: Yes

### 188. [PCCE 기출문제] 4번 / 저축 (pcce_4_saving)

- Time: N/A
- Solved by Myself: Yes
- Notes: Fill-in-the-blank problem.

### 189. 이진수 더하기 (add_binary)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
    - 1st solution: Used a `bool` carry with conditional logic to handle binary addition.
    - 2nd solution: Simplified using integer `carry` with `sum % 2` and `sum / 2`.

### 190. 구슬을 나누는 경우의 수 (number_of_ways_to_choose_balls)

- Time: N/A
- Solved by Myself: No
- Notes:
    - 1st attempt: Failed due to not considering overflow when using factorial.
    - 2nd solution: Used optimized combination formula by iteratively computing $\frac{(n-k+1 \sim n)} {k!}$ to reduce overflow.

### 191. 옹알이 (1) (babbling_1)

- Time: N/A
- Solved by Myself: Yes

### 192. 정수를 나선형으로 배치하기 (place_integers_in_a_spiral)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - Replaced manual direction control with direction arrays (`dr`, `dc`)
    - Simplified movement and direction switching using index rotation `(dir + 1) % 4`

---