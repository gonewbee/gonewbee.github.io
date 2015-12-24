---
layout: post
title:  "FreeRDP编译说明"
date:   2015-12-21 20:12:42
categories: linux
sid:    freerdp_build
---

# xfreerdp

## 多媒体重定向
多媒体重定向使用TSMF通道，编译时可以指定gstreamer版本，如果不指定使用默认版本。使用0.10版本:

```sh
cmake -DCMAKE_BUILD_TYPE=Debug -DWITH_SSE2=ON -DWITH_GSTREAMER_0_10=ON -DWITH_GSTREAMER_1_0=OFF .
```

