CREATE TABLE `contact` (
  `id` int NOT NULL AUTO_INCREMENT,
  `first_name` varchar(45) DEFAULT NULL,
  `last_name` varchar(45) DEFAULT NULL,
  `email` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci

insert into contact (first_name, last_name, email) values ("이","현수","hr2803@naver.com");
insert into contact (first_name, last_name, email) values ("김","현수","kim@naver.com");
insert into contact (first_name, last_name, email) values ("박","현수","park@naver.com");
insert into contact (first_name, last_name, email) values ("유","현수","you@naver.com");