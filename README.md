# c++ practice
## C++
* [高速上手C++11/14](https://legacy.gitbook.com/book/changkun/cpp1x-tutorial/details)
* [rvalue reference &&](https://shininglionking.blogspot.com/2013/06/c-rvalue-reference.html)
* [move semantics(shallow copy)](https://www.youtube.com/watch?v=IOkgBrXCtfo)
  * 避免deep copy物件
* lambda expression(anonymous function)
  * [https://en.wikipedia.org/wiki/Anonymous_function#C++_(since_C++11)](https://en.wikipedia.org/wiki/Anonymous_function#C++_(since_C++11))
  * [http://en.cppreference.com/w/cpp/language/lambda](http://en.cppreference.com/w/cpp/language/lambda)
  * [https://msdn.microsoft.com/zh-tw/library/dd293608.aspx](https://msdn.microsoft.com/zh-tw/library/dd293608.aspx)
  * [https://kheresy.wordpress.com/2010/05/27/c0x%EF%BC%9Alambda-expression/](https://kheresy.wordpress.com/2010/05/27/c0x%EF%BC%9Alambda-expression/)
  * capture: 會用到的變數
* STL documentation:
  * [http://www.cplusplus.com/reference/stl/](http://www.cplusplus.com/reference/stl/)
* auto
  * https://zh.wikipedia.org/wiki/Auto_(C%2B%2B)
  * 用在iterator good
* extern, static
  * https://medium.com/@alan81920/c-c-%E4%B8%AD%E7%9A%84-static-extern-%E7%9A%84%E8%AE%8A%E6%95%B8-9b42d000688f
* std::string
  * https://shaharmike.com/cpp/std-string/
* return reference
  * return的變數必須是static, 否則functino結束stack收回變數就消失了
```
  int& getInt() {
    int i;
    return i;  // DON'T DO THIS.
  }
  
  int& getInt() {
    int* i = new int;
    return *i;  // DON'T DO THIS.
  }
  
  int& getInt()
  {
   static int x = 4;
   return x;  // 
  }
```

## 良好的軟體工程基本原則
* 最小權限原則：利用const於compile time強制執行最小權限原則
* const: 不能改東西
  * const member
    * const int time;
    * const object不能用assign, 必須用初始化設值
  * const memeber function: function不能修改物件內容, 唯讀
    * int getTime() const;
  * const object: 不能呼叫非const的member function

## Makefile
* makefile 介紹與範例程式 http://mropengate.blogspot.com/2018/01/makefile.html
* cmake: https://zh.wikipedia.org/wiki/CMake
  * cmake = "Cross platform MAke", 雖然名字中含有"make"，但是CMake和Unix上常見的「make」系統是分開的，而且更為高階
  
## ctags
* $ sudo yum install -y ctags
* $ ctags -R  // R要大寫
