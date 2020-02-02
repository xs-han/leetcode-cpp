# leetcode-cpp

### 项目介绍
本项目包含leetcode相关的算法练习代码，按照难度，
将代码分别存储easy, medium和hard文件夹下。

为了和leetcode网站的提交格式保持一致，
所有算法均在头文件实现。
不建议在工程实践中使用这种style。

多数problems包含测试代码，在每个难度的test子文件夹下。

### 项目依赖
gtest-1.7.0

使用如下命令安装（已在ubuntu 18.04上测试）
```bash
sudo apt install libgtest-dev
cd /usr/src/gtest
mkdir build && cd build
sudo cmake .. && make && sudo make install
```

相关资源（持续收集中...）
--
[Introduction To Algorithms (MIT Open Course)](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/)

[C++书单(stackoverflow高票当选)](https://stackoverflow.com/questions/388242/the-definitive-c-book-guide-and-list)

[Google编程规范](https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/contents/)

注意事项
--
leetcode网站测试过程中，输入输出流会占用测试时间。
一般来说，可以使用如下代码进行加速。
```c++
#include <iostream>

std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
std::cout.tie(nullptr);
```
具体可参见[Leetcode discussion](https://leetcode.com/discuss/general-discussion/130845/Can-someone-explain-these-codes-(sync_with_stdio(false))-Thanks-a-lot-!/)
