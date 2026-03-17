// longest_file_path returns the character length of the longest absolute path
// to a file in the encoded filesystem string.
// Uses a depth-indexed Vec of cumulative path lengths.
// This runs in O(n) time and O(d) space where d is the max depth.
pub fn longest_file_path(input: &str) -> usize {
    let mut stack: Vec<usize> = vec![0]; // stack[depth] = cumulative parent length
    let mut best = 0usize;

    for line in input.split('\n') {
        let depth = line.bytes().take_while(|&b| b == b'\t').count();
        let name  = &line[depth..];
        let path_len = stack[depth] + name.len();

        if depth + 1 < stack.len() {
            stack[depth + 1] = path_len + 1;
        } else {
            stack.push(path_len + 1);
        }

        if name.contains('.') { // it's a file
            best = best.max(path_len);
        }
    }
    best
}

pub fn problem17() {
    println!("Problem 17:");
    let fs = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    assert_eq!(longest_file_path(fs), 32, "assertion failed");
    assert_eq!(longest_file_path("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"), 20, "assertion failed");
    assert_eq!(longest_file_path("a"), 0, "assertion failed");
    println!("All Tests Passed");
}
