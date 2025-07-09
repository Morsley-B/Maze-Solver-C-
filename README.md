Grid-Based Pathfinding Visualizer(Maze Solver)

This C++ program solves a maze using Breadth-First Search (BFS). It reads the maze from standard input, finds the shortest path from the Start (`S`) to the Goal (`G`), and marks the path using `*`.

What It Does
Reads a 2D grid representing a map, with:
S as the start position
G as the goal
'#' as walls/obstacles
' ' (space) as open paths
Uses Breadth-First Search (BFS) to compute the shortest path from start to goal.
Reconstructs the path once found using parent pointers.
Marks the shortest path on the grid visually.
Handles edge cases where no path is available and provides appropriate output.

Algorithms
Breadth-First Search (BFS) — For shortest path computation in unweighted grids.
Path Reconstruction using Parent Pointers — Traces the optimal path from goal back to start.
No-Path Detection — Determines if the goal is unreachable from the start.

Input Format
The program reads a grid from standard input, with each line representing a row of the map.
Characters used:
S — Start position
G — Goal position
# — Wall
' ' — Open space
