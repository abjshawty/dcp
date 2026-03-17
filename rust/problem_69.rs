pub fn largest_product_of_three(nums: &mut Vec<i64>) -> i64 {
    nums.sort();
    let n = nums.len();
    (nums[n-1]*nums[n-2]*nums[n-3]).max(nums[0]*nums[1]*nums[n-1])
}

pub fn problem69() {
    println!("Problem 69:");
    assert_eq!(largest_product_of_three(&mut vec![-10,-10,5,2]),     500);
    assert_eq!(largest_product_of_three(&mut vec![1,2,3]),           6);
    assert_eq!(largest_product_of_three(&mut vec![-5,-4,-3,-2,-1]), -6);
    println!("All Tests Passed");
}
