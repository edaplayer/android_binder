LOCAL_PATH:=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:=\
	../justd/IBcmDrvBinderService.cpp\
	BpBinderTest.cpp\
	main_client.cpp

LOCAL_SHARED_LIBRARIES:=\
	libcutils\
	libutils\
	libbinder

LOCAL_MODULE:= main_client

include $(BUILD_EXECUTABLE)
