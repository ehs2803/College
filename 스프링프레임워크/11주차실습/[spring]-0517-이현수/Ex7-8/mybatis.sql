create database spring_mybatis character set=utf8;
use spring_mybatis;
CREATE TABLE user_table (
id   int(11) NOT NULL AUTO_INCREMENT,
name  varchar(20) NOT NULL,
phone  varchar(20) DEFAULT NULL,
birthday   datetime  DEFAULT NULL,
PRIMARY KEY (id)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;