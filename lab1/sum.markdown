### 1. strcpy() 使用注意
strcpy(char* des, const char* src), des 指针必须指向一块足够大小的已分配内存，即需要先 malloc 给 des 合适的内存，在复制字符串

### 2. strdup(char* src) 使用注意
strdup 首先调用 malloc 分配与 src 所指向的同样大小的内存，然后将 src 字符串复制到新的内存中，最后将新内存首地址返回，故 strdup 可直接使用

### 3. 结构体指针成员的初始化
结构体指针成员使用前需要初始化，即先分配内存在使用，即使是 strdup 底层还是调用了 malloc 初始化指针内存的

### 4. char* p = "hello" 和 char p[] = "hello" 的区别


### 5. char* s = "hello", *p = s; 和 char *p = (char*)malloc(10); p = strcpy(s); 的区别


### 6. 结构体指针成员初始化总结


### 7. typedef 使用总结


### 8.  -> 和 . 使用


### 9. 结构体 sizeof 大小对齐问题
   
