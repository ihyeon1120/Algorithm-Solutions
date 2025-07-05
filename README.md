# 알고리즘 문제 풀이

이 저장소는 C++과 Python을 사용하여 백준, 코드포스, 프로그래머스 등의 알고리즘 문제를 해결한 코드를 관리하는 공간입니다.

## 🎯 목표

- 자료구조와 알고리즘의 개념을 깊이 있게 이해하고 구현 능력을 향상시킵니다.
- 효율적인 코드 작성과 문제 해결 능력을 훈련합니다.
- AI 개발 및 데이터 엔지니어링에 필요한 탄탄한 CS 기본기를 다집니다.

## 📂 폴더 구조

- **/Data_Structure**: 세그먼트 트리, 유니온-파인드 등 주요 자료구조 관련 문제
- **/DP**: 다이나믹 프로그래밍 관련 문제
- **/Graph**: BFS, DFS, 다익스트라 등 그래프 탐색 관련 문제
- **/Greedy**: 그리디 관련 문제

## ✨ 인상 깊었던 문제들
### 그리디
- **[BOJ 18186: 라면 사기 LARGE](https://github.com/ihyeon1120/Algorithm-Solutions/blob/main/Greedy/buy_ramen_large_18186.py)**
  - 연속되는 3개의 수의 관계를 파악하며 제일 큰 값이 중앙의 위치해 있을 때와 아닐 때의 케이스를 분리하는 것이 핵심 아이디어.
### 세그먼트 트리
- **[BOJ 6549: 히스토그램에서 가장 큰 직사각형](https://github.com/ihyeon1120/Algorithm-Solutions/blob/main/Data_Structure/Segment_tree/biggest_in_hist.cpp)**
  - 분할 정복과 세그먼트 트리를 함께 사용하여 해결한 문제. `mid`가 아닌 `min_idx`로 분할하는 것이 핵심 아이디어.
- **[BOJ 10999: 구간 합 구하기2](https://github.com/ihyeon1120/Algorithm-Solutions/blob/main/Data_Structure/Segment_tree/lazy_segmentTree_10999.cpp)**
  - 느리게 갱신되는 세그먼트 트리 Standard