import System.IO

main:: IO() 
main = menu

menu :: IO()
menu =do
 putStrLn "====== Calculator ======"
 putStrLn "1. Add"
 putStrLn "2. Subtract"
 putStrLn "3. Multiply"
 putStrLn "4. Divide"
 putStrLn "5. Exit"
 putStrLn "Enter your choice:"
 choice <- getLine


 putStrLn "enter the first no: "
 inp1 <-getLine
 let in1 = read inp1
 putStrLn "enter the second no: "
 inp2 <-getLine
 let in2 = read inp2

 run choice in1 in2


run ::(Fractional a,Show a)=> String -> a-> a-> IO()
run "1" in1 in2 = print (add in1 in2) >> menu
run "2" in1 in2= print (sub in1 in2) >> menu
run "3" in1 in2= print (mul in1 in2) >> menu
run "4" in1 in2= print (divide in1 in2) >> menu
run "5" _ _ = print "bye"
run _ _ _= putStrLn "invalid input" >> menu

add :: Num a => a -> a -> a
add x y = x + y

sub :: Num a => a -> a -> a
sub x y = x - y

mul :: Num a => a -> a -> a
mul x y = x * y

divide :: Fractional a => a -> a -> a
divide x y = x / y

