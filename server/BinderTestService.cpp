#include<binder/IServiceManager.h>
#include<binder/IPCThreadState.h>
#include<utils/Log.h>
#include"BinderTestService.h"

namespace android{
//这个函数是将自己注册进servicemanager
void BinderTestService::instantiate(){
    defaultServiceManager()->addService(String16("android.test.IBinderTest"),new BinderTestService);
}
//这个函数是我们要实现的功能，其在BnBinderTest的onTransact中被调用
status_t BinderTestService::binderTest(const char *str)
{
    ALOGI("receive string:%s\n",str);
    printf("print string:%s\n",str);//简单的打印一个字串
    return NO_ERROR;
}

BinderTestService::BinderTestService()
{
    ALOGI("BinderTestService is created");
    printf("BinderTestService is created\n");
}
BinderTestService::~BinderTestService()
{
    ALOGI("BinderTestService is destroyed");
    printf("BinderTestService is destroyed\n");
}

status_t BinderTestService::onTransact(uint32_t code,const Parcel &data,Parcel *reply,uint32_t flags)
{
    ALOGI("BinderTestService onTransact");
    printf("BinderTestService onTransact\n");
    return BnBinderTest::onTransact(code,data,reply,flags);//调用父类的函数
}
};

