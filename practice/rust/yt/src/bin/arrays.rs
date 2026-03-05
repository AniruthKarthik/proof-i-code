#![allow(unused)]

fn main() {
    let arr: [u32; 3] = [1, 2, 3];
    println!("arr[2]={} ", arr[2]);

    let mut arr: [u32; 3] = [1, 2, 3];
    arr[1] = 9;
    let arr: [u32; 10] = [0; 10];
    println!("{:?}", arr);

    let nums: [i32; 10] = [1, 3, 5, 2, 5, 2, 3, 1, 4, 4];

    let s = &nums[0..3];
    println!("{:?}", s);
}

