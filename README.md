# Sort

概统大作业II：随机算法的模拟与分析

## 数据说明

数据放在 `statistics/` 目录。

### 数据格式

第一行两个正整数 $n, T$ 分别表示数据的规模和模拟的次数。

接下来 $T$ 行，每行一个正整数 $cnt$，表示本次模拟的比较次数。

## 暴力算法

### 算法流程

直接模拟经典快排，记录排序次数。

### 测试方法

```bash
make run
```

然后在控制台分别输入 $n, T$ 的值。

如果要命令行指定，可以仿照下面的用法：

```bash
echo 10 10 | make run
```

文件：

```bash
make run < input.txt
```

数据储存在 `statistics/data_origin` 中。



