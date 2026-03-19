import Data.List (sortBy, group, sort, nubBy)
import Data.Ord (comparing, Down(..))

filtervalid= filter (\(_,dist, stat)->stat=="Completed" && dist>0)

countt times=
    let keys=foldr (\t acc-> if t `elem` acc then acc else t:acc) [] times
    in foldl(\acc k->
            let c=length[t| t<-times, t==k]
            in acc ++ [(k,c)] ) [] keys

sortbycount = sortBy (comparing(Down . snd))

main =do 
    let deliveries = [ ("08:00", 15, "Completed"), ("09:30", 20, "Completed")
                     , ("08:00", 10, "Completed"), ("10:15", 25, "Pending")
                     , ("09:30", 30, "Completed"), ("08:00", 12, "Completed") ]
    let cleaned=filtervalid deliveries
    let times= [t | (t,_,_) <-cleaned]
    let counts=countt times
    let res= sortbycount counts

    print res
