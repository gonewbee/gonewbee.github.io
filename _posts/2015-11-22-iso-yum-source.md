---
layout: post
title:  "iso作为yum源"
date:   2015-11-22 11:23:43
categories: summary
sid:    iso_yum_source
---

## 挂载u盘
centos7的iso放在u盘中，将u盘插入后，先挂载u盘，再挂载iso

	# mkdir /mnt/usb
	# mkdir /mnt/iso
	# mount /dev/sdb1 /mnt/usb
	# mount -o loop /mnt/usb/Centos-7.0-1406-x86_64-DVD.iso /mnt/iso

## 修改repo文件
在/etc/yum.repos.d下建立CentOS-Media.repo，内容：
	
	[c5-media]

	name=CentOS-$releasever - Media

	baseurl=file:///mnt/iso/

	gpgcheck=0

	gpgkey=file:///mnt/iso/RPM-GPG-KEY-CentOS-7
