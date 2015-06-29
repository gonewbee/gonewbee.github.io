---
layout: post
title:  "log重定向到文件"
date:   2015-06-29 19:20:30
categories: tools
sid:    log_redirection
---
#1. python2.6和2.7
将print输出到文件

	from __future__ import print_function
	log = open("log.txt", "a") #以追加的方式打开文件
	print("test", file = log)
	log.close()

#2. python3
	import sys
	sys.stdout = open("log.txt", "w")
	print "test"

#3. qt
使用qInstallMsgHandler注册输出的回调。

	FILE *fp=NULL;
	void myMessageOutput(QtMsgType type, const char *msg)
	{
		 //in this function, you can write the message to any stream!
		 switch (type) {
		 case QtDebugMsg:
		     fprintf(fp, "Debug: %s\n", msg); //qDebug会走这个地方。
		     break;
		 case QtWarningMsg:
		     fprintf(fp, "Warning: %s\n", msg);
		     break;
		 case QtCriticalMsg:
		     fprintf(fp, "Critical: %s\n", msg);
		     break;
		 case QtFatalMsg:
		     fprintf(fp, "Fatal: %s\n", msg);
		     abort();
	 	}
	}

	int main(int argc, char **argv)
	{
		fp = fopen("log.txt", "a"); //已追加的方式打开文件
		qInstallMsgHandler(myMessageOutput); //install : set the callback
		QApplication app(argc, argv);
		...
		close(fp);
		return app.exec();
	}

#4 C使用fprintf
在使用fprintf输出时，若想将打印输出到文件可以重新给stderr赋值

	#include <stdio.h>

	int main(int argc, char *argv[]) {
		FILE *fp = NULL;
		fp = fopen("log.txt", "a");
		fprintf(stderr, "hello world:%d\n", argc);	//打印到屏幕上
		stderr = fp;
		fprintf(stderr, "hello world:%d\n", argc);	//stderr赋值后会输出到文件中
		fclose(fp);
		return 0;
	}

