sqr :: Int -> Int 
sqr x=x*x 

isEven :: Int -> Int 
isEven x= x mod 2==0 

gOfX :: Int -> Int 
gOfX x= (x^3)-(2*x)+7 

greatest :: (Int,Int) -> Int 
greatest(x,y)=if (x>y) then x else y 
-- greatest = max 

distBtw :: (Double,Double,Double,Double)-> Double
distBtw x1,x2,y1,y2 = sqrt (sqr (x2-x1)+sqr (y2-y1))

cirAr:: Double-> Double
cirAr r=(22/7)*(r^2)



