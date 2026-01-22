import System.IO 
import System.Exit

calc:: IO()
calc=do 
 putStrLn "Menu"
 putStrLn "1. add"
 putStrLn "2. subtract"
 putStrLn "3. multiply"
 putStrLn "4. divide"
 putStrLn "5. exit"
 putStrLn "ENTER UR CHOICE: "
 choice <- readLn :: IO Int
 if choice == 5 then exitSuccess else if choice > 5 then putStrLn "invalid choice " >> calc else do

  putStrLn "enter the first no: "
  i1 <- readLn :: IO Float
  putStrLn "enter the second no: "
  i2 <- readLn :: IO Float

  perform choice i1 i2 

perform :: (Eq a1, Show a2, Num a1, Fractional a2) => a1 -> a2 -> a2 -> IO ()
perform 1 i1 i2= print(add i1 i2) >> calc
perform 2 i1 i2= print(sub i1 i2) >> calc
perform 3 i1 i2= print(mul i1 i2) >> calc
perform 4 i1 i2= print(divide i1 i2) >> calc

add :: Num a => a -> a -> a
add a b=a+b 

sub :: Num a => a -> a -> a
sub a b=a-b 

mul :: Num a => a -> a -> a
mul a b = a*b 

divide :: Fractional a => a -> a -> a
divide a b =a/b


maxarray []= error "is empty u idiot"
maxarray [x]=x
maxarray (x:xs)
 | x > maxtail = x
 | otherwise = maxtail
 where maxtail= maxarray xs


replicate1 0 _ = []
replicate1 a b = b : replicate1 (a - 1) b

mydrop _ []=[]
mydrop 1 (x:xs)=xs
mydrop a (x:xs)=mydrop (a-1) xs

mytake _ []=[]
mytake 1 (x:xs)=[x]
mytake a (x:xs)= x : mytake (a-1) xs


isthere _ []=False
isthere a (x:xs)
 | a==x = True
 | otherwise = isthere a xs



qsort []=[]
qsort (x:xs)=
 let smallsorted = qsort [a | a<- xs, a<=x]
     bigsorted =qsort [a | a<- xs, a >x]
 in smallsorted ++ [x] ++ bigsorted


limfilttrans :: (a-> Bool) -> (a-> a) -> Int->[a]->[a]
limfilttrans _ f _ []=[]
limfilttrans p f 0 xs=map f xs
limfilttrans p f n (x:xs)
 | p x =f x : limfilttrans p f (n) xs 
 | n > 0= limfilttrans p f (n-1) xs
 | otherwise = f x : limfilttrans p f n xs


removeabc []=[]
removeabc ('a':'b':'c':xs)=removeabc xs
removeabc (x:xs)=x:removeabc xs

abcremove []=[]
abcremove (x:xs)= removeabc x : abcremove xs
