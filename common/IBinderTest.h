#ifndef ANDROID_IHELLOWORLDSERVICE_H
#define ANDROID_IHELLOWORLDSERVICE_H

#include <binder/IInterface.h>

namespace android{

enum {
    HW_HELLOWORLD2=IBinder::FIRST_CALL_TRANSACTION,
};

class IBinderTest: public IInterface//继承自IInterface，用于提供C/S的统一接口
{
public:
    DECLARE_META_INTERFACE(BinderTest);//这是一个宏定义
    virtual status_t binderTest(const char *str)=0;//一个简单的测试函数
};

};

#endif
