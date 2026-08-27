# Level 2 Problems (091 ~ 120)

## Summary
- Total Solved: 10

---

## Problem List

### 91. 후보키 (candidate_key)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
    - 1st solution:
        - Generated all possible combinations of columns.
        - Checked uniqueness for each combination.
        - Removed keys that contained other candidate keys.
    - 2nd solution:
        - Checked minimality before checking uniqueness.
        - Stored only valid candidate keys.
    - 3rd solution:
        - Represented column combinations using bitmasks.
        - Used bitwise operations to efficiently check whether a key contained an existing candidate key.

### 92. 점 찍기 (dot_point)

- Time: N/A
- Solved by Myself: Yes

### 93. N-Queen (n_queen)

- Time: N/A
- Solved by Myself: Yes

### 94. 요격 시스템 (missile_interception)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
    - 1st solution:
        - Sorted targets by their start points.
        - Stored both endpoints of each target with its index and sorted them.
        - Used a stack to group overlapping targets and placed one missile for each group.
    - 2nd solution:
        - Sorted targets by their end points.
        - If the current missile position was less than or equal to the target's start point, placed a new missile and updated its position to the target's end point.

### 95. 혼자서 하는 틱택토 (playing_tictactoe_alone)

- Time: N/A
- Solved by Myself: Yes

### 96. 두 원 사이의 정수 쌍 (integer_pairs_between_two_circles)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Separated the calculation into two cases based on `x`.
    - 2nd solution: Merged the two cases into a single loop using an `if` statement.

### 97. 숫자 블록 (number_block)

- Time: N/A
- Solved by Myself: Yes

### 98. 조이스틱 (joystick)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution:
        - Calculated the character change and cursor movement costs at each position.
        - Used `DFS` to find the best movement.
    - 2nd solution:
        - Separated the character change and cursor movement calculations.
        - Used the fact that there are three possible movement patterns: only right, left then right, and right then left.
        - O(N!) → O(N²)

### 99. 양궁대회 (archery_competition)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Used a `bitmask` to consider all possible cases.
    - 2nd solution: Used `DFS` to consider all possible cases with pruning.

### 100. 혼자 놀기의 달인 (master_of_playing_alone)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Assigned an index to each group and calculated each group size.
    - 2nd solution: Used a `visited` array and directly calculated each group size.

---
