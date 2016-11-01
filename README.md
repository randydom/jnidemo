# jnidemo
C/C++ build shared library to android

1、编译so动态库是在ubuntu下编译的，现在最新的android studio可以集成c++代码和Java一起编译，不需要再单独编译so库
2、demo还有许多C++ <--> Java 的数据结构没有做转换
3、在实际应用的还可以使用swig工具根据C/C++头文件自动生成java代码和C++代码的接口

基本数据类型对应
----------------------------------------
|  Java   | Native   |	Description    |
----------------------------------------
| booleam | jbooleam | unsigned 8 bits |
----------------------------------------
| byte    | jbyte    | signed 8 bits   |
----------------------------------------
| char    | jchar	 | unsigned 16 bits|
----------------------------------------
| short   | jshort   | signed 16 bits  |
----------------------------------------
| int     | jint     | signed 32 bits  |
----------------------------------------
| long    | jlong    | signed 64 bits  |
----------------------------------------
| float   | jfloat   |     32 bits     |
----------------------------------------
| double  | jdouble  |     64 bits     |
----------------------------------------
| void    | void     |     N/A         |
----------------------------------------

------------------------------------------------------------------------------------
|	            Java方法                 |                  对应签名               |
------------------------------------------------------------------------------------
|        booleam isLedOn(void)           | ()Z                                     |
------------------------------------------------------------------------------------
|        void SetLedOn(int ledNo)        | (I)                                     |
------------------------------------------------------------------------------------
|       String substr(String str, 		 |										   |
|           int idx, int count)          | (Ljava/lang/String;II)Ljava/lang/String |
------------------------------------------------------------------------------------
| char fun(int n, String s, int[] value);| (ILjava/lang/String;[I)C                |
------------------------------------------------------------------------------------
| booleam showMsg(View v, String msg);   | (Landroid/View;Ljava/lang/String;)Z     |
------------------------------------------------------------------------------------


http://www.cnblogs.com/shaweng/p/4013320.html 这篇文章讲解的比较好

http://docs.oracle.com/javase/1.5.0/docs/guide/jni/spec/design.html
http://blog.csdn.net/a345017062/article/category/1256568
