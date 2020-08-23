LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= ../sub.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../common
LOCAL_MODULE:= sub
include $(BUILD_SHARED_LIBRARY)
