LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := crypto
LOCAL_SRC_FILES := ./$(TARGET_ARCH_ABI)/libcrypto.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := ssl
LOCAL_SRC_FILES := ./$(TARGET_ARCH_ABI)/libssl.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := endex

LOCAL_C_INCLUDES +=$(LOCAL_PATH)/../include
LOCAL_SRC_FILES := CZsEncrypt.c \
									app_dex_encrypt.c
									
LOCAL_CFLAGS := -std=c99
					
LOCAL_SHARED_LIBRARIES := libcrypto libssl
LOCAL_LDLIBS    := -lm -llog -lz

include $(BUILD_SHARED_LIBRARY)
