def longest_file_path(fs: str) -> int:
    # longest_file_path returns the character length of the longest absolute
    # path to a file in the encoded filesystem string.
    # Uses a depth-indexed stack of cumulative path lengths.
    # This runs in O(n) time and O(d) space where d is the max depth.
    lines = fs.split('\n')
    stack = {0: 0}  # depth -> cumulative length up to (not including) this entry
    best = 0

    for line in lines:
        depth = len(line) - len(line.lstrip('\t'))
        name  = line.lstrip('\t')
        path_len = stack[depth] + len(name)
        stack[depth + 1] = path_len + 1  # +1 for the '/' separator

        if '.' in name:  # it's a file
            best = max(best, path_len)

    return best


def main():
    print("Problem 17:")
    fs = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
    assert longest_file_path(fs) == 32, "assertion failed"
    assert longest_file_path("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") == 20, "assertion failed"
    assert longest_file_path("a") == 0, "assertion failed"
    print("All Tests Passed")
