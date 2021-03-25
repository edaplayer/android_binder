LOCAL_PATH:=$(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=\
	../common/IBinderTest.cpp\
	BnBinderTest.cpp\
	BinderTestService.cpp\
	main_server.cpp

LOCAL_SHARED_LIBRARIES:=\
	libcutils\
	libutils\
	libbinder

LOCAL_MODULE:= main_server

include $(BUILD_EXECUTABLE)
