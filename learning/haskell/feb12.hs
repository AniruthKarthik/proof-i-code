import Data.List (foldl')

sumofalloddsquarelessthantenthousand = sum (map (^2) (filter oddsq [1..100]))
    where oddsq x= odd (x^2)

collatz 1=[1]
collatz x
    | even x= x: collatz (x `div` 2)
    | odd x= (x): collatz (3*x+1)

ispalindrome xs= xs== foldl (flip (:)) [] xs

foldll xs= foldr (\_ sum->sum+1) 0 xs
foldrl xs= foldr (\_ sum->sum+1) 0 xs

prodl xs=foldl' (*) 1 xs

takecubes= takeWhile (<500) (map (^3) [1..])

revfoldl xs=foldl (flip(:)) [] xs
revfoldr xs=foldr (\x acc->acc ++ [x]) [] xs

andr xs=foldr (&&) True

flatten xs= foldr (++) [] xs

listdiff x y=map(\a b->a-b) (zip x y)

maxfold xs=foldr (\ a b->(max a b)) 0 xs
minfold xs=foldl (\ a b->(min a b)) 100000 xs

dupfold xs=foldr (\ a b->(if a `elem` b then b else a:b )) [] xs

facfold xs=foldl (\ b a->b*a) 1 [1..xs]

type Order=(Int,Int)
data DelType= Standard | Distance | Priority

deliveryCharge :: DelType -> Order ->Int
deliveryCharge _ (price,_)
    | price > 200=0
deliveryCharge Standard (_,_)=50
deliveryCharge Distance (_,dist)=dist*8
deliveryCharge Priority (_,dist)=dist*15

totalDel :: DelType -> [Order] ->Int
totalDel dtype= foldl(\acc ord->acc + deliveryCharge dtype ord) 0

custmap f=foldr (\x acc-> f x : acc) []

rotabs xs=foldr (\x acc-> if x=='a' then 'b':acc else if x=='b' then 'c':acc else 'a':acc ) [] xs

-- menu
type Name = String
type Age = Int
type Salary = Double

data Employee = Employee Name Age Salary
  deriving (Show)

-- a) mapEmployee
mapEmployee :: (Name -> Name)
            -> (Age -> Age)
            -> (Salary -> Salary)
            -> Employee
            -> Employee
mapEmployee fn fa fs (Employee n a s) =
  Employee (fn n) (fa a) (fs s)

-- b) nextYear
nextYear :: [Employee] -> [Employee]
nextYear =
  map (mapEmployee id (+1) (*1.2))

-- c) names and salaries with salary < 60000
lowSalary :: [Employee] -> [(Name, Salary)]
lowSalary =
  map (\(Employee n _ s) -> (n, s))
  . filter (\(Employee _ _ s) -> s < 60000)

-- d) names sorted by salary descending
sortedNamesBySalary :: [Employee] -> [Name]
sortedNamesBySalary =
  map (\(Employee n _ _) -> n)
  . sortBy (\(Employee _ _ s1) (Employee _ _ s2) -> compare s2 s1)

-- sample data
employees :: [Employee]
employees =
  [ Employee "Alice" 30 50000
  , Employee "Bob"   45 75000
  , Employee "Carol" 25 40000
  ]

-- menu
menu :: IO ()
menu = do
  putStrLn "1. Show employees"
  putStrLn "2. Next year update"
  putStrLn "3. Employees with salary < 60000"
  putStrLn "4. Names sorted by salary (desc)"
  putStrLn "5. Exit"
  putStrLn "Enter choice:"
  c <- getLine
  case c of
    "1" -> print employees >> menu
    "2" -> print (nextYear employees) >> menu
    "3" -> print (lowSalary employees) >> menu
    "4" -> print (sortedNamesBySalary employees) >> menu
    "5" -> return ()
    _   -> putStrLn "Invalid choice" >> menu

main :: IO ()
main = menu

