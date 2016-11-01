package com.example.tangyi.myapplication;

/**
 * Created by Administrator on 2016/5/17.
 */
public class HellojniCpp {
    public native int add(int a, int b);
    public native int sub(int a, int b);

    public native String strcat(String a);
    static {
        System.loadLibrary("hellocpp");
    }
}
