# Level 0 Problems (151 ~ 180)

## Summary
- Total Solved: 15

---

## Problem List

### 151. 문자열 뒤집기 (reverse_string)

- Time: N/A
- Solved by Myself: Yes

### 152. 배열 만들기 5 (make_array_5)

- Time: N/A
- Solved by Myself: Yes

### 153. 수열과 구간 쿼리 3 (sequence_and_query_3)

- Time: N/A
- Solved by Myself: Yes

### 154. 세 개의 구분자 (three_separators)

- Time: N/A
- Solved by Myself: Yes

### 155. 진료순서 정하기 (emergency_order)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Sorted a copied array and used `find` to determine rank for each element (O(N^2)).
	- 2nd solution: Stored (value, index) pairs, sorted by value in descending order, and assigned ranks directly to original indices (O(N log N)).

### 156. 모스부호 (1) (morse_code_1)

- Time: N/A
- Solved by Myself: Yes

### 157. 팩토리얼 (factorial)

- Time: N/A
- Solved by Myself: Yes

### 158. 숨어있는 숫자의 덧셈 (2) (sum_of_hidden_numbers_2)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Used a string to accumulate digits and converted it to an integer using `stoi`.
	- 2nd solution: Built numbers directly using place value (`num = num * 10 + digit`) to avoid string conversion.

### 159. k의 개수 (count_of_k)

- Time: N/A
- Solved by Myself: Yes

### 160. 가까운 수 (nearest_number)

- Time: N/A
- Solved by Myself: Yes

### 161. 한 번만 등장한 문자 (single_occurrence_char)

- Time: N/A
- Solved by Myself: Yes

### 162. 7의 개수 (count_seven)

- Time: N/A
- Solved by Myself: Yes

### 163. 2의 영역 (range_of_two)

- Time: N/A
- Solved by Myself: Yes
- Notes:
  When using reverse iterators (`rbegin`, `rend`), conversion to a normal iterator is required using `base()`.  
  Note that `base()` returns the iterator pointing to the element *after* the one currently referenced by the reverse iterator, so `-1` adjustment is needed.

### 164. 리스트 자르기 (slice_list) 

- Time: N/A
- Solved by Myself: Yes

### 165. 간단한 논리 연산 (simple_logical_operation)

- Time: N/A
- Solved by Myself: Yes

---