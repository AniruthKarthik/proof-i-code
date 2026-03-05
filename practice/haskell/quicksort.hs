quicksort []=[]
quicksort (x:xs)=
    let smallsorted = quicksort(filter (<=x) xs)
        bigsorted = quicksort(filter (>x) xs)
    in smallsorted ++ [x] ++ bigsorted
