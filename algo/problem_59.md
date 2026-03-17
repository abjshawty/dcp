# Problem 59 — File Syncing Algorithm

**Difficulty:** Medium

## Problem

Given two machines each with a set of files, sync machine B from machine A by transferring only changed files. Use checksums to detect changes.

## Approach — Checksum Comparison

For each file on A, compute its checksum (hash). If B doesn't have the file or its checksum differs, transfer it.

**Time:** O(N) where N is number of files  
**Space:** O(N)
