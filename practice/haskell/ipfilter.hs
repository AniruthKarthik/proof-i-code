prefixfilter [] _ =True
prefixfilter _ [] = False
prefixfilter (p:ps) (x:xs) = p==x && prefixfilter ps xs


filterips [] =[]
filterips (x:xs)
    | prefixfilter "172.161.1" x=x: filterips xs
    | otherwise = filterips xs


main=do 
    let ips = [ "172.161.10.1"
              , "192.168.1.1"
              , "172.161.20.5"
              , "10.0.0.1"
              , "172.161.100.200"
              , "172.162.1.1"
              , "172.161.0.255"
              ]
    let res=filterips ips
    mapM_ putStrLn res
