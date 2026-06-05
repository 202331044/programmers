# Level 1 Problems (061 ~ 088)

## Summary
- Total Solved: 28

---

## Problem List

### 61. 문자열 나누기 (split_string)

- Time: N/A
- Solved by Myself: Yes

### 62. 둘만의 암호 (secret_for_two)

- Time: N/A
- Solved by Myself: Yes

### 63. 대충 만든 자판 (makeshift_keyboard)

- Time: N/A
- Solved by Myself: Yes

### 64. [PCCE 기출문제] 9번 / 이웃한 칸 (pcce_9_adjacent_cells)

- Time: N/A
- Solved by Myself: Yes

### 65. 로또의 최고 순위와 최저 순위 (lotto_rank)

- Time: N/A
- Solved by Myself: Yes

### 66. [1차] 다트 게임 (dart_game)

- Time: N/A
- Solved by Myself: Yes
- Notes: Simplified score tracking by replacing separate previous/current variables with vector and back().

### 67. 완주하지 못한 선수 (incomplete_participant)

- Time: N/A
- Solved by Myself: Yes

### 68. 체육복 (gym_clothes)

- Time: N/A
- Solved by Myself: Yes

### 69. 햄버거 만들기 (make_hamburger)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Used `stack` to manage ingredient states.
	- 2nd solution:
		- Simplified the logic using `vector`.
		- Checked only the last four elements.

### 70. 숫자 짝꿍 (number_partner)

- Time: N/A
- Solved by Myself: Yes

### 71. [PCCE 기출문제] 10번 / 데이터 분석 (pcce_10_data_analysis)

- Time: N/A
- Solved by Myself: Yes

### 72. 크레인 인형뽑기 게임 (claw_machine_game)

- Time: N/A
- Solved by Myself: Yes

### 73. 성격 유형 검사하기 (personality_test)

- Time: N/A
- Solved by Myself: Yes

### 74. 키패드 누르기 (press_keypad)

- Time: N/A
- Solved by Myself: Yes
- Notes:
	- 1st solution: Calculated positions using `map`.
	- 2nd solution: Simplified position calculation using modulo and division.

### 75. 신규 아이디 추천 (recommend_new_id)

- Time: N/A
- Solved by Myself: Yes

### 76. 바탕화면 정리 (desktop_cleanup)

- Time: N/A
- Solved by Myself: Yes

### 77. 개인정보 수집 유효기간 (privacy_expiration)

- Time: N/A
- Solved by Myself: No
- Notes:
    - 1st solution:
        - Parsed dates manually.
        - Calculated expiration dates directly.
        - Failed due to incorrect date calculations.
    - 2nd solution:
        - Used `getline()` to parse dates.
        - Converted dates to total days.
        - Simplified date calculation and comparison.

### 78. 유연근무제 (flexible_workplace)

- Time: N/A
- Solved by Myself: Yes

### 79. 달리기 경주 (running_race)

- Time: N/A
- Solved by Myself: Yes

### 80. 공원 산책 (park_walk)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Handled each direction with separate `if` statements.
    - 2nd solution: Used direction arrays (`dx`, `dy`) to remove duplicated code.

### 81. 중요한 단어를 스포 방지 (word_spoiler_protection)

- Time: N/A
- Solved by Myself: Yes

### 82. 노란불 신호등 (yellow_light)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution:
        - Used a sufficiently large upper bound for the search range.
        - Used a count array to mark yellow-light intervals.
    - 2nd solution:
        - Reduced the search range by computing the LCM of all signal cycles.
    - 3rd solution:
        - Checked whether every signal is in its yellow phase at time `t` using modulo arithmetic.
- References: https://tech.kakao.com/posts/813

### 83. [PCCE 기출문제] 10번 / 공원 (pcce_10_park)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Checked square regions using `BFS`.
    - 2nd solution: Used `dynamic programming` to compute the largest available square.

### 84. [PCCP 기출문제] 1번 / 붕대 감기 (pccp_1_bandage)

- Time: N/A
- Solved by Myself: Yes

### 85. [PCCP 기출문제] 1번 / 동영상 재생기 (pccp_1_video_player)

- Time: N/A
- Solved by Myself: Yes

### 86. 신고 결과 받기 (receive_report_result)

- Time: N/A
- Solved by Myself: Yes

### 87. 택배 상자 꺼내기 (take_out_box)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Simulated the box arrangement using a 2D array.
    - 2nd solution: Determined box coordinates using division and modulo arithmetic.

### 88. 가장 많이 받은 선물 (most_received_gift)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Used `unordered_map` to manage gift histories and gift scores.
    - 2nd solution: Mapped friend names to indices and replaced hash-based structures with vectors.

---
