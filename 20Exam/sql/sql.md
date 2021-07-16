#### --进入master数据库

```sql
use master
```

go  --执行代码块



#### --创建数据库

```sql
Create  database  EmployeeDB
```



#### --判断创建的数据库是否存在，如果存在删除

```sql
if exists (select * from sys.databases where name = 'Employee')

drop database EmployeeDB 
```



#### --删除数据库

```sql
drop database  EmployeeDB

```

go

#### --进入数据库

```sql
use Employee

```

go







#### --删除数据表

```sql
drop table empInfo
```



#### --创建员工的信息表

常用 int  char  varchar



```sql
create table empInfo

{

​	eid int **primary key identity（1001  2）** ,  -- 主键约束  标识符（让当前合理的数据集进行自动增长）主键列（保证数据的唯一性， 而且为非空数据）
  //表示从1001开始，每次增加2



​	eName varchar(20) **unique** not null,  --唯一约束 不能出现重名的名称



​	eAge int not null  **check（eAge>=15 and eAge <=30）**,		--检查约束  保证值在一定的范围内



​	eGender char(2) **check（eGender=‘男’ or Gender='女'）**   **default（‘男’）**not null,   --默认约束



​	eHobby varchar(30)

}

```



#### --创建书本信息表

```sql
create table bookInfo

{	

​		bid int **primary key identity(1,1)**,

​		bName varchar(50) **unique** not null,

​		bAuther  int foreign key references empInfo( eid  //一般是其他表主键  ) not null    //foreign key可以去掉

}
```





#### --插入数据

```sql
insert into Emplnfo(eid, eName, eAge, eGender, eHobby )values(1, 'jim'， 19，‘男’ ，null)

insert into Emplnfo(eid, eName, eAge, eGender, eHobby )values(2, 'Tom'， 20，‘女’ ，null)
//设置主键后eid不能自己插入

insert into bookInfo values('西游记'， 1003)

```



#### --删除数据

```sql
delete from BookInfo  where bName = '西游记'

delete from emoInfo where eAge =19 and eGender =‘女‘

delete  from  empInfo  where  eHobby  is null  

Delete  from empInfo where eAge = 20 or eHobby is not null and eGender = '女'
```



####  --修改数据

```sql
update  empInfo set eHobby='玩王者'  where  eName = ‘tom’

update  empInfo set eHobby='玩王者' ， eAge = 17,   where  eName = ‘tom’

```



#### --查询数据

```sql
select * from emplnfo  where eAge=19
```



#### 五个约束

主键约束

唯一约束

检查约束

默认约束

外键约束



create table userINfo



 

#### --普通查询  带条件查询  全连接查询  左连接  右连接  子查询  分组  排序  查询  聚合函数

- 普通查询

  ```sql
  SELECT channel_id AS one, view_count AS two FROM bilibili  //取别名
  ```

- 带条件的查询

  ```sql
  SELECT * FROM bilibili WHERE like_count > 5000
  ```

- 模糊查询

  ```sql
  select * from userinfo where uname like '%m'  //以m结尾
  select * from userinfo where uname like 'j%'  //以j开头
  select * from userinfo where uname like '%i%'  //中间有i
  ```

- 排序(order by 在使用时 默认为生序（asc）降序（desc）)

  所有的排序 都是在整个查询语句数据查询完成以后再去接排序 （order一般放最后）

  ``` sql
  select * from userinfo where uname like '%i%' order by uage desc, uid
  ```

- 分组

  ```sql
  select uage, ugender，count（*）  as num    from userInfo 
  where uage>20 
  group by ugender, uage
  order by gender desc      //count是聚合函数, 先筛选分组，最后排序
  ```

- 取数据前几项

  ```sql
  select  top 3  name, uage  from userInfo where ugender='男' order  by  uage desc 
  ```

- having(查询之后再查询)

  ```sql
  select uage, ugender，count（*）  as num    from userInfo 
  where uage>20 
  group by ugender, uage
  having count(*) = 1
  ```

- 求和  平均数 最大值 最小值. 去掉重复

  ```sql
  select SUM(uage) as agesum from userInfo   //求和
  select avg(uage) as ageavg from userInfo    //平均
  select max(uage) as agemax from userInfo		//最大值
  select min(uage) as agemin from userInfo		//最小值
  select distinct uage, agender from userInfo  //去重
  ```

- 求一定范围内的值

  ```sql
  select * from userInfo where uage >= 17 and uage <= 21
  select * from userInfo where between 17 and 21
  select * from userInfo where uage < 17 or uage > 21
  select * from userInfo where uage != 17
  select * from userInfo where uage <> 17
  select * from userInfo where uage in (17,19,21)
  select * from userInfo where uage not in (17, 19, 21)
  ```

- 链接表查询(查多张表)

  --全链接

  ```sql
  select * from bookInfo b 
  inner join userInfo u on b.bauthor = u.uid     // 全链接
  where u.uage > 19
  ```

  --左连接

  ```sql
  select * from bookInfo b
  left join userInfo u on b.bauther = u.uid
  ```

  --右连接

  ```sql
  select * from bookInfo b
  right join userInfo u on b.bauther = u.uid
  ```

  --联合查询

  ```sql
  select * from userInfo
  union
  select * from bookInfo
  
  select uname as name  from userInfo
  union all
  select bname from bookInfo
  ```

- 子查询

  ```sql
  select uage from userInfo where uname 'tom'
  
  select * from userInfo where uage > (select uage from userInfo where uname 'tom')
  
  select (uage+1) as uage , * from userInfo where uage < (select avg(uage) as ageavg from userInfo)
  ```

  











## K8S

- 进程：一个程序执行起来，它就从磁盘上的二进制文件，变成i算计内存的数据，寄存器里的值，堆栈中的指令，被打开的文件，以及各种设备的状态信息的总和。像这样一个程序运起来后的计算机执行环境的总和，就是我们今天的主角：进程。

- 容器技术的核心功能，就是通过约束和修改进程的动态表现，从而为其创造出一个”边界“

- 对于Docker等大多数Linux容器来说，**Cgroups技术**是用来制造约束的主要手段，

  而**Namespace技术**是用来修改进程视图的主要方法





#### 容器编排

#### 集群管理

#### 负载均衡





```html
.a{
	position absolute //绝对定位，元素离开自己当前的位置，后面的元素会占据空余的位置
	left:50%
	z_index:1
}

.b{
	position relative //相对定位，元素离开自己当前的位置 后面的元素不会占据他的位置，原来的位置继续保留
	left:50%
	z-index:2 
}

.c{
	position:fied;	//固定定位，以当前屏幕为标准，固定在当前屏幕的某个位置		
	width:50px;
	height:50px;
  right:5px;
  bottom:0px;
  bacnground-color:skyblue;
  color:red;
}
```

