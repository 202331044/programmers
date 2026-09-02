# Level 2 Problems (091 ~ 120)

## Summary
- Total Solved: 15

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

### 101. [PCCP 기출문제] 3번 / 충돌위험 찾기 (finding_collision_risks)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Counted the number of robots at each position for every time step.
    - 2nd solution:
        - Generated the complete route of each robot first.
        - Counted collisions at each time step.
        - Separated route generation from collision detection, making the logic simpler and easier to follow.

### 102. 택배 배달과 수거하기 (delivery_and_pick)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Calculated the maximum distance for each trip by processing deliveries and pickups separately.
    - 2nd solution: Simplified the solution by processing deliveries and pickups together using cumulative quantities, starting from the farthest house.

### 103. 바이러스 파이프 (virus_pipe)

- Time: N/A
- Solved by Myself: Yes
- Notes: 
    - Separated the code into `DFS` and `BFS` parts.
    - Used `BFS` to spread the virus along the selected pipe type and `DFS` to explore different pipe type sequences.

### 104. 순위 검색 (ranking_search)

- Time: N/A
- Solved by Myself: Yes
- Notes:
    - 1st solution: Separated cases using a multi-dimensional vector.
    - 2nd solution: Generated all possible keys using bitmasking and used binary search to count matching scores.

### 105. 멀쩡한 사각형 (normal_rectangle)

- Time: N/A
- Solved by Myself: No
- Notes:
    - Used the formula `w + h - gcd(w, h)` to calculate the number of broken squares.
    - Subtracted the broken squares from the total area `w * h`.
 
---
