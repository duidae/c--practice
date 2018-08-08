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
  * return的變數必須是static, 否則function結束stack收回變數就消失了
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
    return x;  // OK
  }
```
* convert string to char* in C++
  * https://stackoverflow.com/questions/12862739/convert-string-to-char
```
std::string s0 = "hello";
const char *s1;
s1 = s0.c_str();
```
* c++繼承,多重繼承
  * https://openhome.cc/Gossip/CppGossip/MultiInheritance1.html
```
class FooC : public FooA, public FooB {  // C繼承A+B
}
```
* c++ explicit
  * http://ot-note.logdown.com/posts/173174/note-cpp-named-type-convertion
  * 由於編譯器 (compiler) 有可能自動在建構函數 (constructor) 的參數 (parameter) 進行隱性型態轉換 (implicit type conversion) ，也就是將參數轉換成類別型態，因而造成一些奇怪的結果，這時需要把建構函數宣告為 explicit ，使之禁止編譯器進行轉換工作
  * explicit关键字到底是什么作用呢？它的作用就是禁止轉換。如文章一开始而言，凡是用explicit关键字修饰的构造函数，编译时就不会进行自动转换，而会报错。
* override
  * https://kheresy.wordpress.com/2014/10/03/override-and-final-in-cpp-11/
* include 雙引號 角括號
  * https://msdn.microsoft.com/zh-tw/library/36k2cdd4.aspx
* template
  * http://rocksaying.tw/archives/3641717.html
* enum
  * 建議使用 enum 來做狀態的判斷，以下方法不但直覺而且所佔的記憶體也少，不管你設了幾個列舉，他都只占一個 int (32 bit) 的記憶體位置
```
enum GameStatus
{
  Menu,      // 開頭選單
  Loading,   // 載入畫面
  Playing,   // 遊戲進行中
  Pause,     // 遊戲暫停
  GameOver   // 遊戲結束
}
 
GameStatus status = GameStatus.Menu;
 
if ( status == GameStatus.Menu )
{
  // 開頭選單處理......
}
if ( status == GameStatus.Playing )
{
  // 遊戲進行中處理......
}
```
* serialization序列化
   * 為了傳遞object或把object寫入硬碟，透過serialization將object傳輸或放在File等.....
* extern
  * https://medium.com/@alan81920/c-c-%E4%B8%AD%E7%9A%84-static-extern-%E7%9A%84%E8%AE%8A%E6%95%B8-9b42d000688f

## 良好的軟體工程基本原則
* 最小權限原則：利用const於compile time強制執行最小權限原則
* const: 不能改東西
  * const member
    * const int time;
    * const object不能用assign, 必須用初始化設值
  * const memeber function: function不能修改物件內容, 唯讀
    * int getTime() const;
  * const object: 不能呼叫非const的member function
  * const pointer: 不能修改pointer
    * const char* the_string
    * char* const the_string
    * const char* const the_string
```
char* the_string : I can change the char to which the_string points, and I can modify the char at which it points.
const char* the_string : I can change the char to which the_string points, but I cannot modify the char at which it points.
char* const the_string : I cannot change the char to which the_string points, but I can modify the char at which it points.
const char* const the_string : I cannot change the char to which the_string points, nor can I modify the char at which it points.
```
## GCC compiler
* 安裝gcc 8.1.0
  * https://com-it.tech/archives/37312

## Makefile
* makefile 介紹與範例程式 http://mropengate.blogspot.com/2018/01/makefile.html
* cmake: https://zh.wikipedia.org/wiki/CMake
  * cmake = "Cross platform MAke", 雖然名字中含有"make"，但是CMake和Unix上常見的「make」系統是分開的，而且更為高階
* TODO
  * makefile練習
  
## Compile, linking
* undefine reference to/未定義參考XXXX
  * https://blog.csdn.net/cserchen/article/details/5503556
  * -L 指定的路径, 从左到右依次查找
  * 连接库参数的顺序不对 在默认情况下,对于-l 使用库的要求是越是基础的库越要写在后面,无论是静态还动态
* link static library(libXXX.a)
  * $ cc -o yourprog yourprog.c libstatic.a
* 理清gcc、libc、libstdc++的关系
  * https://blog.csdn.net/haibosdu/article/details/77094833

## GCC
* 在CentOS上裝gcc devtoolset
  * devtoolset是由CERN維護
    * https://www.softwarecollections.org/en/scls/rhscl/devtoolset-7/
    * scl enable devtoolset-7 bash只是临时覆盖系统原有的GCC引用，如果想永久覆盖，可在.bashrc文件中添加source /opt/rh/devtoolset-7/enable
    * http://blog.fungo.me/2016/03/centos-development-env/
* 裝新的gcc
  * https://jdhao.github.io/2017/09/04/install-gcc-newer-version-on-centos/
* gcc 常見錯誤解析
  * http://b8807053.pixnet.net/blog/post/337965512-gcc-%E5%B8%B8%E8%A6%8B%E9%8C%AF%E8%AA%A4%E8%A7%A3%E6%9E%90

## ctags
* $ sudo yum install -y ctags
* $ ctags -R  // R要大寫

## IDE
* VS code
  * "editor.fontSize": 18,
  * "editor.fontWeight": "bold"
