// supress warnings
#![allow(unused)]

// enables struct printing format
#[derive(Debug)]
struct Lang {
    lang: String,
    version: String,
}

fn main() {
    let lang = "rust";
    println!("hello {} {}", lang, lang);
    println!("hello {lang}");

    let x = 2;
    println!("{0} x {0} = {1} ", x, x * x);

    let l = Lang {
        lang: "rust".to_string(),
        version: "1.38".to_string(),
    };
    println!("{:?}", l);
    println!("{:#?}", l);
}
