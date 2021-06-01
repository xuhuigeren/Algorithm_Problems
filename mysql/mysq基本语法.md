##  创建数据表

**语法**

创建MySQL数据表需要以下信息：

- 表名
- 表字段名
- 定义每个表字段

```
CREATE TABLE table_name (column_name column_type);
```



##  删除数据

**语法**

> ==**delete**==
>
> 1. 属于DML语言，每次删除一行，都在事务日志中为所删除的每行记录一项。产生rollback，事务提交之后才生效;如果有相应的 trigger,执行的时候将被触发，如果删除大数据量的表速度会很慢。
> 2. 删除表中数据而不删除表的结构(定义)，同时也不释放空间。
>
> ==**truncate**==
>
> 1. 只能操作表，将表中数据全部删除，在功能上和不带where子句的delete语句相同
>
> 2. 默认情况下，truncate通过释放存储表数据所用的数据页来删除数据，并且只在事务日志中记录页的释放。所以使用的系统和事务日志资源少，可以使用reuse storage; truncate会将高水线复位(回到最开始).
> 3. truncate是DDL语言, 操作立即生效,自动提交，原数据不放到rollback segment中,不能回滚. 操作不触发trigger.
> 4. 删除内容、释放空间但不删除表的结构(定义)。
>
> ==**drop**==
>
> 1. drop语句将删除表的结构，以及被依赖的约束(constrain),触发器(trigger),索引(index);
> 2. 删除之后，依赖于该表的存储过程/函数将保留,但是变为invalid状态.
> 3. drop也属于DDL语言，立即执行，执行速度最快
> 4. 删除内容和定义，释放空间。
>
> ==**区别**==
>
> 1、表和索引所占空间：
> 　　当表被TRUNCATE 后，这个表和索引所占用的空间会恢复到初始大小；
> 　　DELETE操作不会减少表或索引所占用的空间；
> 　　DROP语句将表所占用的空间全释放掉。
> 　　
> 2、应用范围：
> 　　TRUNCATE 只能对table；
> 　　DELETE可以是table和view。
>
> 3、执行速度：
> 　　drop > truncate > delete
>
> 4、delete from删空表后，会保留一个空的页，truncate在表中不会留有任何页。
>
> 5、DELETE语句执行删除的过程是每次从表中删除一行，并且同时将该行的删除操作作为事务记录在日志中保存以便进行进行回滚操作。
> 　　TRUNCATE TABLE 则一次性地从表中删除所有的数据并不把单独的删除操作记录记入日志保存，删除行是不能恢复的。并且在删除的过程中不会激活与表有关的删除触发器。执行速度快。
>
> 6、当使用行锁执行 DELETE 语句时，将锁定表中各行以便删除。truncate始终锁定表和页，而不是锁定各行。
>
> 7、如果有identity产生的自增id列，delete from后仍然从上次的数开始增加，即种子不变；
> 　使用truncate删除之后，种子会恢复到初始值。



```
delete  from table_name [where Clause];

truncate table table_name;

drop table table_name;
```



## 插入数据

**语法**

```
INSERT INTO table_name ( col1_name, col2_name,...col3_name )
                       VALUES
                       ( value1, value2,...valueN );
```

* 如果数据是字符型，必须使用单引号或者双引号，如："value"。

  

##  查询数据

**语法**

```
SELECT [DISTINCT] column_name,column_name
FROM table_name
[WHERE Clause]
[LIMIT N][ OFFSET M]
```

- DISTINCT关键字直接放在列名的前面，去重
- 查询语句中你可以使用一个或者多个表，表之间使用逗号(,)分割，并使用WHERE语句来设定查询条件。
- SELECT 命令可以读取一条或者多条记录。
- 你可以使用星号（*）来代替其他字段，SELECT语句会返回表的所有字段数据
- 你可以使用 WHERE 语句来过滤或者包含任何条件，**在同时使用ORDER BY和WHERE子句时，应
  该让ORDER BY位于WHERE之后，否则将会产生错误，GROUP BY子句必须出现在WHERE子句之后，ORDER BY子句之前            where----------->group by----------(having)-------->order by---------->limit**
- 你可以使用 LIMIT 属性来设定返回的记录数。
- 你可以通过OFFSET指定SELECT语句开始查询的数据偏移量。默认情况下偏移量为0。

