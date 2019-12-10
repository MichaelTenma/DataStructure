# DataStructure
 
#### (1) 在学生选课数据库studentcourse中新建一名为stud_view的视图，该视图可以让我们看到每个学生的姓名、选修的课程名和成绩。
```SQL
CREATE VIEW stud_view
AS
BEGIN
	SELECT SC1.学号,SC1.姓名,C.课程名,SC1.成绩
		FROM C
			RIGHT OUTER JOIN
			(SELECT S.学号,S.姓名,SC.课程号,SC.成绩
				FROM S LEFT OUTER JOIN SC
				ON S.学号 = SC.学号
			) AS SC1
			ON C.课程号 = SC1.课程号
END
```
#### (3) 在学生选课数据库studentcourse中新建视图teacher_view，该视图显示每个教师所教的课程名，和选修该课程的学生人数。
```SQL
CREATE VIEW teacher_view
AS
BEGIN
	SELECT C.教师,C.课程名,COUNT(DISTINCT SC.学号) AS 选修人数
		FROM C LEFT OUTER JOIN SC ON C.课程号 = SC.课程号
		GROUP BY C.教师,C.课程名
END
GO
```
#### (5) 在学生选课数据库studentcourse中创建视图depart_view，该视图可以用来查看每个系的学生人数。
```SQL
CREATE VIEW depart_view
AS
BEGIN
	SELECT S.系,COUNT(DISTINCT S.学号) AS 人数 FROM S
		GROUP BY S.系
END
GO
```
#### (1) 在studentcourse数据库中创建存储过程，存储过程名为proc_1，要求实现如下功能：根据学生学号，查询该学生的选课情况，其中包括该学生的学号、姓名、性别、课程号、课程名和成绩。执行该存储过程，查询学号为J0401学生的选课情况。
```SQL
CREATE PROC proc_1 @xuehao CHAR(6) AS
BEGIN
	SELECT S.姓名,S.性别,SC1.*
		FROM S INNER JOIN
		(SELECT SC.学号,SC.课程号,C.课程名,SC.成绩
			FROM SC INNER JOIN C
			ON SC.学号 = @xuehao
			AND SC.课程号 = C.课程号
		) AS SC1
		ON S.学号 = SC1.学号
END
GO
EXEC proc_1 @xuehao='J0401'
GO
```
#### (2) 在studentcourse数据库中创建存储过程，存储过程名为proc_2，要求实现如下功能：根据课程号，查询某门课程的选课学生情况，其中包括课程号、课程名、学号、姓名、系和性别。执行存储过程，查询课程号为C01的选课学生情况。
```SQL
CREATE PROC proc_2 @kechenghao CHAR(3) AS
BEGIN
	SELECT SC1.*,S.姓名,S.系,S.性别
	FROM S INNER JOIN
		(SELECT C.课程号,C.课程名,SC.学号
			FROM SC INNER JOIN C
				ON SC.课程号=@kechenghao
				AND SC.课程号 = C.课程号
		) AS SC1
		ON SC1.学号 = S.学号
END
GO
EXEC proc_2 @kechenghao = 'C02'
GO
```
#### (3) 在studentcourse数据库中创建触发器，触发器名为trigger_2，要求实现如下功能：当修改课程表C中的数据时（包括插入、更新和删除操作），显示提示信息“课程表被修改了”。
```SQL
CREATE TRIGGER trigger_1 
	ON C AFTER INSERT,DELETE,UPDATE
AS
BEGIN
	SELECT '课程表被修改了'
END
GO
```
