---
layout: post
title:  "mysql学习"
date:   2015-06-21 11:20:10
categories: mysql
sid:    mysql_learn
---
# 1. 开始 #

## 1.1 控制命令 ##
+ ubuntu下安装：sudo apt-get install mysql-server mysql-client
+ 重启mysql服务：sudo service mysql restart
+ 登陆：mysql -u root -p
+ 退出：quit

## 1.2 常用命令 ##

### 1.2.1 database命令
+ 列出所有数据库：show databases;
+ 创建数据库：create database mywork;
+ 使用数据库：use mywork;
+ 删除数据库：drop database notes;
+ 创建utf8编码数据库：

		create database mywork default character set utf8 COLLATE utf8_general_ci;

### 1.2.2 table命令
+ 列出所有表：show tables;
+ 新建表：create table notes (des varchar(40), cmd varchar(80), time timestamp NOT NULL default CURRENT_TIMESTAMP);
+ 查看表的构成：describle notes;
+ 插入：insert into notes values ("安装pip", "sudo apt-get install python-pip", null);
+ 删除：delete from notes where des="安装pip";
+ 修改：update notes set des="ubuntu安装pip" where des="安装pip";
+ 查找：select * from notes where des="ubuntu安装pip";
+ 删除表：drop table notes;
+ 清空表：delete from notes;