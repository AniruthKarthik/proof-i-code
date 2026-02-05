#![allow(unused)]

fn main() {
    let i0: i8 = 0; // range -> mod | 2 power 8-1 |
    let i0: i16 = 0; // range -> mod | 2 power 16-1 |

    // type conversion
    let i: i32 = 1;
    let u: u32 = i as u32;
    let x: u32 = u + (i as u32);
}
