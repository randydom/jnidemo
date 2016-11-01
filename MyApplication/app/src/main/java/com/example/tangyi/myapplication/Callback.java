package com.example.tangyi.myapplication;

/**
 * Created by Administrator on 2016/5/16.
 */
import android.util.Log;
public class Callback {
    public void Test(){
        Log.d("Callback","test callback ...");
    };
    public void Testparam(String a){
        Log.d("Callback","test param:"+a);
    };
    public int add(int a ,int b){
        int c = a+b;
        Log.d("Callback","add:"+c);
        return c;
    };
}
