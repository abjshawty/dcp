# Problem 81 — Phone Number Letter Combinations

**Difficulty:** Easy

## Problem

Given a string of digits and a phone keypad mapping, return all possible letter combinations.

## Approach — Recursive Backtracking

For each digit, iterate its mapped letters. Recursively combine with all combinations of the remaining digits. Base case: empty digits returns `[""]`.

**Time:** O(4^N × N)  
**Space:** O(4^N × N)
