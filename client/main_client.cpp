#define LOG_TAG "bindermain"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <utils/RefBase.h>
#include "../common/IBinderTest.h"

using namespace android;

int main(int argc,char *argv[])
{
    ALOGI("HelloWorldSevice client is starting now");
    //获取ServiceManager，从而能得到远程IBinder，实现通信
    sp<IServiceManager> sm =defaultServiceManager();
    sp<IBinder> b;
    sp<IBinderTest> sBinderTest;

    do{
        b=sm->getService(String16("android.test.IBinderTest"));
        if(b != 0){
            break;
        }
        ALOGI("BinderTest is not working,waiting...");
        printf("BinderTest is not working,waiting...\n");
        usleep(500000);
    }while(true);
    sBinderTest = interface_cast<IBinderTest>(b);
    sBinderTest->binderTest("Hello,World!\n");
    return 0;
}
