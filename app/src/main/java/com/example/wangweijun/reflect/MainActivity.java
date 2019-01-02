package com.example.wangweijun.reflect;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    JNI jni = new JNI();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }

    public void cCalljavaByReflect(View view) {
        jni.callback();
    }


    public void callbackint(View view) {
        jni.callbackInt();
    }

    public void callbackString(View view) {
        jni.callbackString();
    }

    public void callbackString2(View view) {
//        jni.callbackString("中国你好");
    }

    public void showToast(String s) {
        Toast.makeText(this, s, Toast.LENGTH_LONG).show();
    }

    public native void showToast();

    public void callbackToast(View view) {
        showToast();
    }
}
