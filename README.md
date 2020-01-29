# leetcode-cpp

### 项目介绍
本项目包含leetcode相关的算法练习代码，按照难度，
将代码分别存储easy, medium和hard文件夹下。

为了和leetcode网站的提交格式保持一致，
所有算法均在头文件实现。
不建议在工程实践中使用这种style。

一部分problems包含测试代码，在每个难度的test子文件夹下。

### 项目依赖
gtest

具体来说使用如下命令安装（已在ubuntu 18.04上测试）
```bash
sudo apt install libgtest-dev
cd /usr/src/gtest
mkdir build && cd build
sudo cmake .. && make && sudo make install
```

相关资源（持续收集中...）
--
[Introduction To Algorithms (MIT Open Course)](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/)
