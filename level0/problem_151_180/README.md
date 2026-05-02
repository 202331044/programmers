# Level 0 Problems (151 ~ 180)

## Summary
- Total Solved: 30

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

### 166. 문자열 반복해서 출력하기 (repeat_string_output)

- Time: N/A
- Solved by Myself: Yes

### 167. A로 B 만들기 (transform_a_to_b)

- Time: N/A
- Solved by Myself: Yes
- Notes:
  - 1st solution: Used `map<char, int>` to count character frequencies of both strings and compared them.
  - 2nd solution: Used a fixed-size vector (size 26) to count frequencies by incrementing for `before` and decrementing for `after`.
  - Optimized by using a single array instead of two maps, reducing overhead and improving performance.
 
### 168. 수열과 구간 쿼리 4 (sequence_and_query_4)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Handled the `k == 0` case separately by assuming only index 0 is affected.
	- 2nd solution: Skipped the `k == 0` case and only processed valid step sizes.

### 169. 문자열 묶기 (group_strings)

- Time: N/A
- Solved by Myself: Yes

### 170. 컨트롤 제트 (control_z)

- Time: N/A
- Solved by Myself: Yes

### 171. 잘라서 배열로 저장하기 (split_into_array)

- Time: N/A
- Solved by Myself: Yes

### 172. 커피 심부름 (coffee_errand)

- Time: N/A
- Solved by Myself: Yes

### 173. 배열 만들기 6 (make_array_6)

- Time: N/A
- Solved by Myself: Yes

### 174. 조건에 맞게 수열 변환하기 2 (transform_sequence_by_condition_2)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Compared the entire vector with a previous copy to check if any changes occurred.
	- 2nd solution: Tracked changes during iteration using a flag to avoid unnecessary vector comparison.

### 175. 왼쪽 오른쪽 (left_right)

- Time: N/A
- Solved by Myself: Yes

### 176. qr code (qr_code)

- Time: N/A
- Solved by Myself: Yes

### 177. 특수문자 출력하기 (print_special_characters.cpp)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Printed special characters using escape sequences.
	- 2nd solution: Simplified using raw string literals.

### 178. 소인수분해 (prime_factorization)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Used a `set` to store prime factors while dividing `n`.
	- 2nd solution: Divided `n` repeatedly by each factor and added it once, avoiding the need for a `set`.

### 179. 문자 개수 세기 (count_characters)

- Time: N/A
- Solved by Myself: Yes

### 180. 문자열 여러 번 뒤집기 (reverse_string_multiple_times)

- Time: N/A
- Solved by Myself: Yes

---