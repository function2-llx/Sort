# Sort

概统大作业II：随机算法的模拟与分析

## 数据说明

数据放在 `statistics/` 目录。因为肯定很大，使用 git-lfs 进行管理，可能需要提前安装好，否则容易出错。

```bash
sudo apt install git # 更新git
sudo apt install git-lfs # 有时候会有蜜汁提示告诉你 git-lfs坏了，需要先这样装一下
git lfs install
```

尽量在装好git-lfs后再 clone 仓库。如果本地不能正常显示数据（给你显示一堆SHA1啥的），尝试

```bash
git lfs pull
```

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



