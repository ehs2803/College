create function inst_advise_student(@inst_name varchar(20))
returns integer
begin
	declare @s_count integer;
	select @s_count=count(*)
	from instructor, advisor
	where name=@inst_name and ID=i_ID
	return @s_count
end
