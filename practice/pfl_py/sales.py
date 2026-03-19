from functools import reduce

sales_data = [
    {"product": "Laptop", "units_sold": 120, "price_per_unit": 999.99},
    {"product": "Smartphone", "units_sold": 75, "price_per_unit": 499.99},
    {"product": "Tablet", "units_sold": 45, "price_per_unit": 299.99},
    {"product": "Headphones", "units_sold": 150, "price_per_unit": 79.99},
    {"product": "Smartwatch", "units_sold": 20, "price_per_unit": 199.99},
]

minu = 50
withrev = list(
    map(
        lambda p: {**p, "total_sales": p["units_sold"] * p["price_per_unit"]},
        sales_data,
    )
)

totrev = reduce(lambda acc, p: acc + p["total_sales"], withrev, 0)
# print(totrev)

filtered = list(filter(lambda p: p["units_sold"] >= minu, withrev))

for p in filtered:
    print(f"{p['product']}: {p['units_sold']} units")

sorteddata = sorted(filtered, key=lambda p: p["total_sales"], reverse=True)
for p in sorteddata:
    print(f"{p['product']}: ${p['total_sales']}")
