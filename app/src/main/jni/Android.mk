LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := ccalljava
LOCAL_SRC_FILES =: ccalljava.c
LOCAL_LDLIBS += -llog

APP_ABI := all
include $(BUILD_SHARED_LIBRARY)