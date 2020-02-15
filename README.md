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

网站测试结果
--
每个问题取Runtime最短的一次测试作为统计结果。

| #问题 | 难度 | Runtime | Memory | Runtime Beats |
| :--- | :--- | :---    | :---   | :---   |
| 0001 | Easy   | 8ms   | 10.2MB    | 93.46%  |
| 0002 | Medium | 24ms  | 11.2MB    | 78.65%  |
| 0003 | Medium | 12ms  | 9.2MB     | 84.40%  |
| 0004 | Hard   | 16ms  | 9.5MB     | 91.51%  |
| 0005 | Medium | 0ms   | 10MB      | 100.00% |
| 0006 | Medium | 8ms   | 9.7MB     | 94.47%  |
| 0007 | Easy   | 0ms   | 8.2MB     | 100.00% |
| 0008 | Medium | 4ms   | 8.4MB     | 84.90%  |
| 0009 | Easy   | 8ms   | 9.3MB     | 90.44%  |
| 0010 | Hard   | 4ms   | 8.5MB     | 93.40%  |
| 0011 | Medium | 0ms   | 9.9MB     | 100.00% |
| 0012 | Medium | 0ms   | 8.6MB     | 100.00% |
| 0013 | Easy   | 4ms   | 8.7MB     | 98.46%  |
| 0014 | Easy   | 4ms   | 8.9MB     | 96.08%  |
| 0015 | Medium | 96ms  | 14.8MB    | 86.88%  |
| 0016 | Medium | 4ms   | 8.7MB     | 99.17%  |
| 0017 | Medium | 0ms   | 8.7MB     | 100.00% |
| 0018 | Medium | 4ms   | 9.5MB     | 99.93%  |
| 0019 | Medium | 4ms   | 8.9MB     | 90.71%  |
| 0020 | Easy   | 0ms   | 8.7MB     | 100.00% |
| 0021 | Easy   | 8ms   | 9.5MB     | 85.59%  |
| 0022 | Medium | 4ms   | 18.3MB    | 87.84%  |
| 0023 | Hard   | 16ms  | 12.3MB    | 99.97%  |
| 0024 | Medium | 0ms   | 8.7MB     | 100.00% |
| 0025 | Hard   | 20ms  | 11.4MB    | 85.84%  |
| 0026 | Medium | 16ms  | 10.1MB    | 99.40%  |
| 0027 | easy   | 0ms   | 8.6MB     | 100.00% |
| 0028 | easy   | 0ms   | 9.2MB     | 100.00% |
| 0029 | medium | 0ms   | 8.4MB     | 100.00% |
| 0030 | hard   | 36ms  | 23.9MB    | 86.23%  |
| 0031 | medium | 4ms   | 8.8MB     | 98.93%  |
| 0032 | hard   | 0ms   | 9.8MB     | 100.00% |
| 0033 | medium | 0ms   | 8.8MB     | 100.00% |
| 0034 | medium | 4ms   | 10.6MB    | 99.45%  |
