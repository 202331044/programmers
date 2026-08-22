# Level 2 Problems (091 ~ 120)

## Summary
- Total Solved: 5

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

---
