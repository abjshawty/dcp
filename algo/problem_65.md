# Problem 65 — Spiral Matrix

**Difficulty:** Medium

## Problem

Given an M×N matrix, return elements in spiral order (clockwise from top-left).

## Approach — Layer Peeling

Maintain four boundaries (top, bottom, left, right). Traverse right, down, left, up; shrink each boundary after traversal. Stop when boundaries cross.

**Time:** O(M×N)  
**Space:** O(M×N) for output
