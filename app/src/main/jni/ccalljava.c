#include <jni.h>
#include <stdlib.h>
#include <android/log.h>

#define LOG_TAG "wangweijun"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

JNIEXPORT void JNICALL Java_com_example_wangweijun_reflect_JNI_callback
        (JNIEnv * env, jobject thiz) {
    LOGD("log from jni java call c of callback");
    // 找到字节码
    jclass clazz = (*env)->FindClass(env, "com/example/wangweijun/reflect/JNI");
    // 找到方法id
    jmethodID methodId = (*env)->GetMethodID(env, clazz, "helloFromJava", "()V");
    // 调用
    (*env)->CallVoidMethod(env, thiz, methodId);
}



JNIEXPORT void JNICALL Java_com_example_wangweijun_reflect_JNI_callbackInt
        (JNIEnv * env, jobject thiz) {
    LOGD("JNI_callbackInt");
    // 找到字节码
    jclass clazz = (*env)->FindClass(env, "com/example/wangweijun/reflect/JNI");
    // 找到方法id  下面是获取方法的签名
    // jni_c_reflect\app\build\intermediates\javac\debug\compileDebugJavaWithJavac\classes
    // javap -s com.example.wangweijun.reflect.JNI
    jmethodID methodId = (*env)->GetMethodID(env, clazz, "add", "(II)I");
    int result = (*env)->CallIntMethod(env, thiz, methodId, 3, 4);
    LOGD("result: %d", result);
}

/*
 * Class:     com_example_wangweijun_reflect_JNI
 * Method:    callbackString
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_wangweijun_reflect_JNI_callbackString
        (JNIEnv * env, jobject thiz) {
    LOGD("JNI_callbackString");
    // 找到字节码
    jclass clazz = (*env)->FindClass(env, "com/example/wangweijun/reflect/JNI");
    // 找到方法id  下面是获取方法的签名
    // jni_c_reflect\app\build\intermediates\javac\debug\compileDebugJavaWithJavac\classes
    // javap -s com.example.wangweijun.reflect.JNI, 最后一个是
    jmethodID methodId = (*env)->GetMethodID(env, clazz, "printString", "(Ljava/lang/String;)V");

    jstring jstr = (*env)->NewStringUTF(env, "hello");
    (*env)->CallVoidMethod(env, thiz, methodId, jstr);
}

JNIEXPORT void JNICALL Java_com_example_wangweijun_reflect_MainActivity_showToast
        (JNIEnv * env, jobject thiz) {
    LOGD("MainActivity_showToast");
    // 找到字节码
    jclass clazz = (*env)->FindClass(env, "com/example/wangweijun/reflect/MainActivity");
    // 找到方法id  下面是获取方法的签名
    jmethodID methodId = (*env)->GetMethodID(env, clazz, "showToast", "(Ljava/lang/String;)V");

    jstring jstr = (*env)->NewStringUTF(env, "hello");
    (*env)->CallVoidMethod(env, thiz, methodId, jstr);
}
