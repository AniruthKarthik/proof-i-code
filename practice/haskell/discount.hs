main=do 
    let prices = [800.0,1200.0,1500.0,3000.0,2200.0,950.0,1800.0,2700.0,500.0,2999.0]
    let discounted =[if p > 1000 && p<2001 then (0.9 * p) else p | p <- prices]
    let finalpr=[if p > 2500 then (0.95 * p) else p | p<- discounted]
    print finalpr
