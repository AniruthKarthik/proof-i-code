f1 1=[1]
f1 n 
 | even n = n : f1 (n `div` 2)
 | otherwise = n: f1 (5*n+1)


f2 :: [Int] -> Int -> [Int]
f2 [] _ =[]
f2 [x] _=[x]
f2 (x:y:xs) d 
 | y-x==d = x: f2(y:xs) d 
 | otherwise = f2(x:xs) d 
