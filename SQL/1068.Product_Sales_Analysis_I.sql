# Write your MySQL query statement below
select product_name, year, price
FROM Sales S
LEFT JOIN Product P
ON S.product_id=P.product_id;