sepage [] les gre= [les,gre]
sepage (x:xs) les gre
    | x >=18 = sepage xs les (x:gre)
    | otherwise = sepage xs (x:les) gre

sep xs =sepage xs [] []
