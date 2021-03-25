#define LOG_TAG "main_server"

#include<binder/IPCThreadState.h>
#include<binder/ProcessState.h>
#include<binder/IServiceManager.h>
#include<utils/Log.h>
#include"BinderTestService.h"

using namespace android;

int main(int argc,char *argv[]){
    BinderTestService::instantiate();//注册进servicemanager中
    //开启线程池，接收处理Client发送的进程间通信请求
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}
