package com.example.wangweijun.reflect;

import android.util.Log;

public class JNI {
    static {
        System.loadLibrary("ccalljava");
    }

    public void helloFromJava() {
        Log.i("wangweijun", "hello From Java");
    }

    public int add(int x, int y) {
        return x+y;
    }

    public void printString(String s) {
        Log.i("wangweijun", s);
    }

    public native void callback();

    public native void callbackInt();

    public native void callbackString();

}
