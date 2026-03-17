toPairs :: [Int] -> [(Int,Int)]
toPairs [] = []
toPairs (a:b:xs) = (a,b) : toPairs xs
toPairs _ = error "Invalid list"

toPoly :: [(Int,Int)] -> String
toPoly [] = ""
toPoly ((c,d):xs)
    | d == 0 = show c ++ rest
    | d == 1 = show c ++ "x" ++ rest
    | otherwise = show c ++ "x^" ++ show d ++ rest
  where
    rest = case xs of
        [] -> ""
        _  -> " + " ++ toPoly xs

deriveTerm :: (Int,Int) -> (Int,Int)
deriveTerm (c,d)
    | d == 0 = (0,0)
    | otherwise = (c*d, d-1)

nonZero :: (Int,Int) -> Bool
nonZero (c,_) = c /= 0

derivePoly :: [(Int,Int)] -> [(Int,Int)]
derivePoly terms = filter nonZero (map deriveTerm terms)

fromPairs :: [(Int,Int)] -> [Int]
fromPairs [] = []
fromPairs ((c,d):xs) = [c,d] ++ fromPairs xs

process :: [Int] -> IO ()
process lst = do
    let pairs = toPairs lst
    putStrLn $ "Symbolic Form: " ++ toPoly pairs

    let dPairs = derivePoly pairs
    putStrLn $ "Derivative: " ++ toPoly dPairs

    putStrLn $ "Output List: " ++ show (fromPairs dPairs)

main :: IO ()
main = do
    let input = [2,3,4,2,5,1,14,0]
    process input
