# Write your MySQL query statement below
select name as Customers
from Customers
where Id NOT IN(
    select customerid
    from Orders
)