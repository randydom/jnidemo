package com.example.tangyi.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity {
    Hello hello = new Hello();
    Hellojni helloj = new Hellojni();
    HellojniCpp hellojni_cpp = new HellojniCpp();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        hello.say();
        testlocalstudent();
        int d = helloj.add(3,4);
        int e = helloj.sub(4,3);
        teststudent();
        teststudenton();
        testcallback();
        testhellocpp();
        String c = "nihhao";
       String f = helloj.addstr(c);
        Log.d("Hellojni", "string:" + f);
        Log.d("Hellojni","d:" + d + ",e:"+ e);
        int[] ci = {1,2,31};
        Log.d("hellocpp","addarr:"+helloj.addarr(ci,3));
    }
    public void teststudent(){
        Student s = new Student();
        Log.d("Hellojni","start");
        s.age = 23;
        s.name = "tangyi";
        Student b = helloj.getstudent(s);
        Log.d("Hellojni", "name:" + b.name + ",age:" + b.age);
    }
    public void testlocalstudent(){
        Student s = new Student();
        s.age = 2;
        s.name = "teste";
    }
    public void teststudenton(){
        Studentone s = new Studentone(23);
        Log.d("Hellojni","father name:"+ s.s.father);
        //Studentone t = helloj.getstudentone(s);
        Studentone.cla c = Studentone.cla.THREE;
        Studentone.cla a = helloj.getcla(c);
        Log.d("Hellojni","a:"+a.toString());
        //Log.d("Hellojni","t = cla"+t.cs +"father name:"+ t.s.father + "mother name:"+t.s.mother+"inttotal:"+t.card[0]);
    };
    public void testcallback(){
        Callback call = new Callback();
        helloj.callback(call);
    };
    public void testhellocpp(){
        int a  = hellojni_cpp.add(2,3);
        int ab  = hellojni_cpp.sub(2, 3);

        String c = "tangyi";
        Log.d("hellocpp","a:"+a+",b:"+ab);
        Log.d("hellocpp","strcat:"+hellojni_cpp.strcat(c));
    };
}
