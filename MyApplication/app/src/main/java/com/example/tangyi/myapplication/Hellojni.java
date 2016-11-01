package com.example.tangyi.myapplication;

/**
 * Created by Administrator on 2016/5/12.
 */
public class Hellojni {
    public native int add(int a, int b);
    public native int sub(int a, int b);
    public native int addarr(int[] a,int len);
    public native String addstr(String a);
    public native Student getstudent(Student s);
    //public native Studentone getstudentone(Studentone s);
    public native Studentone.cla getcla(Studentone.cla a);
    public native void callback(Callback back);
    static {
        System.loadLibrary("hello");
    }
}