select count(*)
from instructor, advisor
where name='Lembr' and ID=i_ID

select *
from instructor

select *
from advisor

select dbo.inst_advise_student('Lembr')