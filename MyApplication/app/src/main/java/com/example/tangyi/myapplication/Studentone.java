package com.example.tangyi.myapplication;

/**
 * Created by Administrator on 2016/5/16.
 */
public class Studentone {
    public int age;
    public enum cla{
        ONE,TWO,THREE
    };
    public class family{
        public String father;
        public String mother;
        public family(){
            father = "wang2";
            mother = "guihua";
        };
    };
    family s;
    cla cs = cla.THREE;
    public int[] card;
    public family[] families;
    public Studentone(int sage){
        age = sage;
        card = new int[]{10,11,12,13};
        s  = new family();
    };
    public family[] setFamilies(){
        families = new family[1];
        return families;
    };
}
