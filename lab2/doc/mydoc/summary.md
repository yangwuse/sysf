### 1. 什么是头文件被重复引用？
由 #include 嵌套引起的一个头文件被重复引用
假如 main.cpp #include "a.h" 和 #include "b.h" 两个头文件，
如果在 a.h 中包含 b.h，那么 main.cpp 就引用了两次 b.h 文件

### 2. 如何避免头文件被重复引用？
在每个头文件中使用标准格式：
#ifndef A_H    // 如果 a.h 没有定义
#define A_H 1  // 宏定义
// code 
#endif
虽有重复，但利大于弊

### 3. #define 宏定义使用
1. #define 为宏定义指令，作用是用字符串简单替换宏名
2. 宏定义格式： #define 宏名 字符串
    #define N 1
3. 所有预处理指令以 # 开头，由预处理器解析
    #ifndef/#define/#endif
4. 宏名一般全大写，属于标识符
    #denfine PI 3.1415
5. 字符串可以为数字、表达式、函数
    #define M (n*n + 4)
    #define F max(a, b) return a > b ? a : b;
6. 宏定义括号不能少，避免歧义
    #define M1 n + 4 和 #define M2 (n + 4) 展开区别
    5 * M1 // 5 * n + 4
    5 * M2 // 5 * (n + 4)
7. 宏定义允许嵌套定义
    #define A 1
    #define B 3*A // B -> 3

### 4. #define 和 typedef 的区别和注意事项
1. #define P1 int* 
2. typedef int* P2 
3. P1 a, b; // int* a, b // b 为 int 变量
4. P2 a, b; // a, b 都为 int* 变量
5. define 只是字符替换，而 typedef 创建一个新类型名

### 5. getchar 的读取原理

### 6. duplicate symbol '_main' in: 
一个项目中只能有一个 main 函数，运行调试项目前(多个 .cpp 和 .h 文件)
前删除测试文件，确保整个项目只有一个 main 函数
