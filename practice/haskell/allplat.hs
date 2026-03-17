allplat :: Eq a=> [a] -> [[a]]
allplat []=[]
allplat (x:xs)=
    (x:same): allplat rest
    where 
    (same,rest)=span (==x) xs
