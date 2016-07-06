DROP SCHEMA IF EXISTS `test`;
CREATE SCHEMA `test`;
USE `test`;


CREATE TABLE Company(
    companyName     CHAR(30),
    id              INTEGER(4) PRIMARY KEY
);

CREATE TABLE EmployeesHired(
    id              INTEGER(4),
    numHired        INTEGER(4),
    fiscalQuarter   INTEGER(4),
    FOREIGN KEY fk_id(id) REFERENCES Company(id)
);

CREATE TABLE TestNumber(
    num INTEGER(4)
);


INSERT INTO TestNumber(num) VALUES(5);
INSERT INTO TestNumber(num) VALUES(23);
INSERT INTO TestNumber(num) VALUES(-6);
INSERT INTO TestNumber(num) VALUES(7);

INSERT INTO Company(companyName, id) VALUES('Hillary Plumbing', 6);
INSERT INTO Company(companyName, id) VALUES('Jhon Lawn Company', 9);
INSERT INTO Company(companyName, id) VALUES('Dave Cookie Company', 19);
INSERT INTO Company(companyName, id) VALUES('Jane Electricity', 3);

INSERT INTO EmployeesHired(id, numHired, fiscalQuarter) VALUES(3, 3, 3);
INSERT INTO EmployeesHired(id, numHired, fiscalQuarter) VALUES(3, 2, 4);
INSERT INTO EmployeesHired(id, numHired, fiscalQuarter) VALUES(19, 4, 1);
INSERT INTO EmployeesHired(id, numHired, fiscalQuarter) VALUES(6, 2, 1);


--
select c.companyName 
from Company as c, EmployeesHired as eh 
where c.id = eh.id and eh.fiscalQuarter = 4;

select companyName 
from Company join EmployeesHired 
on Company.id = EmployeesHired.id and EmployeesHired.fiscalQuarter = 4;

--
select companyName 
from Company 
where id not in (select id from EmployeesHired where numHired > 0);

--
select companyName, COALESCE(SUM(numHired), 0) as quantity 
from Company left join EmployeesHired on Company.id = EmployeesHired.id 
group by Company.id 
order by companyName;



select DISTINCT num
from TestNumber 
where num not in (
    select l.num 
    from TestNumber as l join TestNumber as g 
    where l.num < g.num
);


