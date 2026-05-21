# Level 1 Problems (031 ~ 060)

## Summary
- Total Solved: 25

---

## Problem List

### 31. 최대공약수와 최소공배수 (gcd_lcm)

- Time: N/A
- Solved by Myself: Yes
- Notes: Refactored using `std::gcd` and removed redundant code.

### 32. 크기가 작은 부분 문자열 (small_substring)

- Time: N/A
- Solved by Myself: Yes

### 33. 예산 (budget)

- Time: N/A
- Solved by Myself: Yes
- Notes: Simplified code by removing redundant conditions.

### 34. 삼총사 (three_musketeers)

- Time: N/A
- Solved by Myself: Yes

### 35. 이상한 문자 만들기 (make_weird_string)

- Time: N/A
- Solved by Myself: Yes

### 36. 3진법 뒤집기 (reverse_ternary)

- Time: N/A
- Solved by Myself: Yes

### 37. 최소직사각형 (minimum_rectangle)

- Time: N/A
- Solved by Myself: Yes

### 38. 가장 가까운 같은 글자 (closest_same_char)

- Time: N/A
- Solved by Myself: Yes

### 39. 시저 암호 (caesar_cipher)

- Time: N/A
- Solved by Myself: Yes
- Notes:  Simplified the code using `% 26`.

### 40. 두 개 뽑아서 더하기 (pick_two_sum)

- Time: N/A
- Solved by Myself: Yes

### 41. 푸드 파이트 대회 (food_fight_contest)

- Time: N/A
- Solved by Myself: Yes

### 42. K번째수 (kth_number)

- Time: N/A
- Solved by Myself: Yes

### 43. 숫자 문자열과 영단어 (number_string_words)

- Time: N/A
- Solved by Myself: Yes

### 44. 콜라 문제 (cola_problem)

- Time: N/A
- Solved by Myself: Yes
- Notes: Simplified the logic by tracking only the current bottle count.

### 45. 명예의 전당 (1) (hall_of_fame_1)

- Time: N/A
- Solved by Myself: Yes

### 46. 문자열 내 마음대로 정렬하기 (custom_string_sort)

- Time: N/A
- Solved by Myself: Yes

### 47. 카드 뭉치 (card_bundle)

- Time: N/A
- Solved by Myself: Yes

### 48. [1차] 비밀지도 (secret_map)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution:
        - Converted each map into `vector<string>`.
        - Merged the two maps by comparing each character.

    - 2nd solution:
        - Used bitwise OR (`|`) to merge the maps.
        - Used bit masking to determine walls (`#`) and spaces (` `).

### 49. 추억 점수 (yearning_score)

- Time: N/A
- Solved by Myself: Yes

### 50. 폰켓몬 (ponketmon)

- Time: N/A
- Solved by Myself: Yes
- Notes:     
    - Simplified the code using the range constructor of `unordered_set`.
    - Used `min()` to return the result more concisely.

### 51. 기사단원의 무기 (knight_weapon)

- Time: N/A
- Solved by Myself: Yes

### 52. 모의고사 (mock exam)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution:
        - Used `vector<pair<int, int>>` and sorting to rank students by score.
        - The return logic was hard-coded and less maintainable.
    - 2nd solution:
        - Found the maximum score first and selected students matching it without sorting.
        - Simplified the logic and removed unnecessary sorting.

### 53. 2016년 (year_2016)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Simulated the calendar by increasing the date one day at a time.
    - 2nd solution:
        - Calculated the total number of days by adding the days of each month.
        - Removed unnecessary daily simulation.

### 54. 덧칠하기 (paint)

- Time: N/A
- Solved by Myself: Yes
- Notes: Simplified the solution by tracking the last painted position.

### 55. [PCCE 기출문제] 9번 / 지폐 접기 (pcce_9_fold_bill)

- Time: N/A
- Solved by Myself: Yes

---
