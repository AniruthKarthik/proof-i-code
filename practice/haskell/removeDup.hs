removedup []=[]
removedup (y:ys) =
    let rest=removedup ys
    in if y `elem` rest
        then rest
        else y: rest



consecremdup []=[]
consecremdup (y:ys)=
    y: consecremdup rest
    where
    (dups,rest)=span (==y) ys
    
