LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := cam_cli.c
LOCAL_MODULE := libopx_cam
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
