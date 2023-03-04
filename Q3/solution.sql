with t1 as (select a.article_id, a.owner_id, c.category_id
from article a
left join category_article_mapping c
on a.article_id=c.article_id
),
t2 as (select a.owner_id, a.category_id, o.owner_name
from t1 a
left join owner o
on all.owner_id = o.owner_id),
t3 as 
(select owner_id, owner_name, count(distinct category_id) as different_category_count
from t2
group by owner_id, owner_name)
select * from t3
order by different_category_count desc