---
layout: post
title:  "golang生成目录嵌套json使用jstree显示"
date:   2015-08-27 21:13:52
categories: golang
sid:    jstree_golang_json
---

+ 目的：在浏览器上浏览电脑指定目录。
+ 技术：golang，jstree

# 1. golang生成jstree识别的json

## 1.1 使用"io/ioutil"读取指定目录
```go
fileinfos, err := ioutil.ReadDir(dirpath)
if err != nil {
	log.Println("ReadDir error!" + dirpath)
}
```

## 1.2 使用"encoding/json"生成json数据
```go
type treestate struct {
	Opened   bool `json:"opened"`
	Disabled bool `json:"disabled"`
	Selected bool `json:"selected"`
}

type filetree struct {
	Id       string            `json:"id"`
	Text     string            `json:"text"`
	Icon     string            `json:"icon,omitempty"`
	State    *treestate        `json:"state,omitempty"`
	Children bool              `json:"children,omitempty"`
	Li_attr  map[string]string `json:"li_attr,omitempty"`
	A_attr   map[string]string `json:"a_attr,omitempty"`
}
```

### 1.2.1 忽略为空的项
在声明struct时对不必要的项添加omitempty，这样在生成json时如果该项为空就会忽略。

### 1.2.2 嵌套json
+ struct中嵌套struct，如*treestate

```go
state := &treestate{Selected: true} // Selected为true的话，在jstree中会默认选中
tree.State = state
```
+ struct中使用map，如map[string]string

```go
// A_attr的href项表示该文件选项的链接地址
tree.A_attr = map[string]string{"href": "/download?file=" + tree.Id}
```

# 2. jstree使用ajax
```html
<div id="using_ajax"></div>
<script type="text/javascript">
$('#using_ajax').jstree({
  'core' : {
    'data' : {
      'url' : "/tree_file",
      "dataType" : "json",
      'data' : function (node) {
        if (node.id==='#') {
          return { 'id' : "D:" }; //根目录为D盘
        } else {
          return { 'id' : node.id };
        }
      }
    }
  }
});
</script>
```

### 完整代码：
[tree.html](https://github.com/zhangshy/netfiles/blob/master/static/test/tree.html)
[treefile.go](https://github.com/zhangshy/netfiles/blob/master/pcshow/treefile.go)