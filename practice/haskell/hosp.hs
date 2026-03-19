import System.Exit
fee x xs
    | x<5 =0
    |otherwise = (if xs=="general" then 500 else 1200)

emerginsurance x y
    | x && y = 400
    | x && not y= 800
    | otherwise= 400


olderdis x= if x> 60 then 300 else 0

con2bool "yes" = True
con2bool "no" = False
con2bool _= False

main =do 
    putStrLn "Hospital menu"
    putStrLn "enter age"
    age <- readLn :: IO Int
    putStrLn "enter consultant"
    cons <-getLine
    putStrLn "is it emergency"
    emer <- getLine
    putStrLn "do u have insurance"
    ins <-getLine
    
    
    let fees= fee age cons
    let emerins= emerginsurance (con2bool emer) (con2bool ins)
    let tot= fees + emerins - olderdis age
    
    putStrLn ("total bill " ++ show tot)

    putStrLn "do u want to continue" 
    ch <-getLine

    if con2bool (ch) then main else exitSuccess
