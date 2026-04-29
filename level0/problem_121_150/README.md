# Level 0 Problems (121 ~ 150)

## Summary
- Total Solved: 30

---

## Problem List

### 121. 조건에 맞게 수열 변환하기 3 (transform_sequence_by_condition_3)

- Time: N/A
- Solved by Myself: Yes

### 122. n의 배수 (multiple_of_n)

- Time: N/A
- Solved by Myself: Yes

### 123. 첫 번째로 나오는 음수 (first_negative)

- Time: N/A
- Solved by Myself: Yes

### 124. 문자열의 앞의 n글자 (first_n_chars_of_string)

- Time: N/A
- Solved by Myself: Yes

### 125. 문자열 잘라서 정렬하기 (split_and_sort_string)

- Time: N/A
- Solved by Myself: Yes

### 126. n 번째 원소까지 (elements_up_to_n)

- Time: N/A
- Solved by Myself: Yes

### 127. 꼬리 문자열 (tail_string)

- Time: N/A
- Solved by Myself: Yes

### 128. 접미사인지 확인하기 (check_suffix)

- Time: N/A
- Solved by Myself: Yes
- Notes:
  - 1st solution: Compared characters one by one from the end of the string.
  - 2nd solution: Extracted the suffix part using `substr` and compared it directly with the target string.

### 129. 더 크게 합치기 (largest_by_concatenation)

- Time: N/A
- Solved by Myself: Yes

### 130. 글자 이어 붙여 문자열 만들기 (make_str_by_joining_chars)

- Time: N/A
- Solved by Myself: Yes

### 131. 피자 나눠 먹기 (2) (divide_pizza_2)

- Time: N/A
- Solved by Myself: Yes
- Notes:
  - 1st solution: Increased a multiplier until 6 * cnt became divisible by n.
  - 2nd solution: Used the LCM formula to directly compute the result.

### 132. 외계행성의 나이 (alien_age)

- Time: N/A
- Solved by Myself: Yes

### 133. 이차원 배열 대각선 순회하기 (traverse_diagonal_in_2d_array)

- Time: N/A
- Solved by Myself: Yes
- Notes:
  - 1st solution: Used nested loops with separate boundary checks (`i < h`, `j < w`) and the condition `i + j <= k`.
  - 2nd solution: Combined boundary and condition checks directly into the loop conditions.

### 134. 날짜 비교하기 (compare_dates)

- Time: N/A
- Solved by Myself: Yes
- Notes:
  - 1st solution: Compared each date component (year, month, day) one by one.
  - 2nd solution: Used lexicographical comparison of vectors to compare dates directly.

### 135. 글자 지우기 (remove_chars)

- Time: N/A
- Solved by Myself: Yes

### 136. 등차수열의 특정한 항만 더하기 (selective_arithmetic_sum)

- Time: N/A
- Solved by Myself: Yes

### 137. 문자열 섞기 (interleave_strings)

- Time: N/A
- Solved by Myself: Yes

### 138. 수열과 구간 쿼리 1 (sequence_and_query_1)

- Time: N/A
- Solved by Myself: Yes

### 139. 1로 만들기 (make_one)

- Time: N/A
- Solved by Myself: Yes

### 140. 합성수 찾기 (find_composite_numbers)

- Time: N/A
- Solved by Myself: Yes

### 141. 특별한 이차원 배열 2 (special_2d_array_2)

- Time: N/A
- Solved by Myself: Yes

### 142. l로 만들기 (convert_to_l)

- Time: N/A
- Solved by Myself: Yes

### 143. 특별한 이차원 배열 1 (special_2d_array_1)

- Time: N/A
- Solved by Myself: Yes

### 144. 배열 회전시키기 (array_rotation)

- Time: N/A
- Solved by Myself: Yes

### 145. 2차원으로 만들기 (convert_to_2d)

- Time: N/A
- Solved by Myself: Yes

### 146. 중복된 문자 제거 (remove_duplicate_chars)

- Time: N/A
- Solved by Myself: Yes

### 147. 배열의 길이를 2의 거듭제곱으로 만들기 (resize_array_to_power_of_two)

- Time: N/A
- Solved by Myself: Yes

### 148. 빈 배열에 추가, 삭제하기 (add_remove_empty_array)

- Time: N/A
- Solved by Myself: Yes

### 149. 문자열이 몇 번 등장하는지 세기 (count_str_occurrences)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Used nested loops to compare characters one by one.
	- 2nd solution: Used `substr` to extract substrings and compare them with the target string.

### 150. 특정 문자열로 끝나는 가장 긴 부분 문자열 찾기 (longest_substring_ending_with)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Extracted substrings starting at each index and compared with the target string.
	- 2nd solution: Iterated from the end and checked substrings ending with the target string.
	- 3rd solution: Used `string::rfind` to find the last occurrence of the target string.

---