---
layout: post
title:  "ubuntu打包deb"
date:   2015-06-20 10:50:25
categories: linux
sid:    create_deb
---
# 1. 打包deb #
参考[Ubuntu下的deb包制作详解](http://blog.csdn.net/small_qch/article/details/6967654)

## 1.1 目录结构 ##
DEBIAN大写、用来制作打包文件，另一个opt时安装的路径，当使用dpkg -i安装时，opt下的文件会复制到/opt/下。

	.
	└── xfreerdp
	    ├── DEBIAN
	    │   ├── control
	    │   ├── debian-binary
	    │   ├── postinst
	    │   └── postrm
	    └── opt
	        └── xfreerdp
	            ├── bin
	            │   └── xfreerdp
	            ├── conf
	            │   ├── Icon_xfreerdp.png
	            │   ├── xfreerdp.conf
	            │   └── xfreerdp.desktop
	            └── lib
	                ├── libfreerdp-client.so.1.2
	                ├── libwinpr.so.1.1
	                └── libxfreerdp-client.so.1.2

## 1.2 dpkg命令 ##
+ 生成deb包：dpkg -b xfreerdp xfreerdp.deb
+ 安装：sudo dpkg -i xfreerdp.deb

## 1.3 DEBIAN目录 ##

### 1.3.1 control
包含软件名、版本和依赖关系等内容。

	Package: xfreerdp-my-X11 #软件名称，使用sudo dpkg -r XXX 卸载时使用
	Source: xfreerdp
	Version: 1.2.0	#版本
	Architecture: amd64	#64位，i386是32
	Maintainer: ZhangShy  <zhang_syi@massclouds.com>
	Installed-Size: 250
	Provides: masscloud
	Section: x11
	Priority: optional
	Homepage: http://www.massclouds.com/
	Description: xfreerdp

### 1.3.2 debian-binary
	$ cat xfreerdp/DEBIAN/debian-binary 
	2.0

### 1.3.3 postinst
安装时执行的脚步，可以没有这个文件，755权限。将xfreerdp编译的so库放到/opt/xfreerdp/lib下后，运行/opt/xfreerdp/bin/xfreerdp时会提示找不到so库，可以使用

	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/xfreerdp/lib
指定动态库位置，当这样指定当前会话有效，若想所有的用户都有效，在/etc/ld.so.conf.d/中添加，并运行ldconfig。postinst文件内容：

	cp /opt/xfreerdp/conf/xfreerdp.conf /etc/ld.so.conf.d/
	ldconfig
xfreerdp.conf内容：

	/opt/xfreerdp/lib/

### 1.3.4 postrm
卸载时执行的脚步，可以没有这个文件，755权限。postrm文件内容：

	rm -rf /etc/ld.so.conf.d/xfreerdp.conf
	ldconfig

# 2. 添加桌面快捷方式 #
需要将xfreerdp.desktop文件复制到Desktop下。

## 2.1 xfreerdp.desktop ##
	[Desktop Entry]
	Name=xfreerdp
	Name[zh_CN]=远程桌面	#应用中文名称
	Exec=/opt/xfreerdp/bin/xfreerdp %f	#应用执行命令，%f是打开某个文件时传递的参数
	MimeType=application/msword;text/plain;	#该应用可以打开的文件
	Icon=/usr/share/icons/Icon_xfreerdp.png	#应用图标
	Terminal=false
	Type=Application
	Categories=Network;GNOME;TextEditor;Office;

## 2.2 postinst ##
	cp /opt/xfreerdp/conf/Icon_xfreerdp.png /usr/share/icons/
	for name in `ls /home`
	do
	  if [ -d /home/$name ]
	  then
	    cp -p /opt/xfreerdp/conf/xfreerdp.desktop /home/$name/Desktop #cp -p保持文件所属用户
	  fi
	done

## 2.3 postrm ##
	rm -rf /usr/share/icons/Icon_xfreerdp.png
	for name in `ls /home`
	do
	  if [ -d /home/$name ]
	  then
	    rm -rf /home/$name/Desktop/xfreerdp.desktop
	  fi
	  if [ -d /home/$name/.config/freerdp ]
	  then
	    rm -rf /home/$name/.config/freerdp
	  fi
	done

# 3. 指定文件的默认打开方式 #
修改mimeinfo.cache文件，将自己的应用添加到指定类型后，该文件的位置。

	/usr/share/applications
	/usr/local/share/applications
	~/.local/share/applications

## 3.1 postinst ##
	cp /opt/xfreerdp/conf/xfreerdp.desktop ~/.local/share/applications
	if grep 'msword' ~/.local/share/applications/mimeinfo.cache
	then
	    sed -i "s/msword=/msword=xfreerdp.desktop;/g" ~/.local/share/applications/mimeinfo.cache
	else
	   sed -i '$a application\/msword=xfreerdp.desktop;' ~/.local/share/applications/mimeinfo.cache
	fi
