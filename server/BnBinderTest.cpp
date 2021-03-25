#include <binder/Parcel.h>
#include "BnBinderTest.h"

namespace android {
//对BnBinderTest的onTransact实现，还会在后面其子类BnBinderTestService中重写此方法
status_t BnBinderTest::onTransact(uint32_t code,const Parcel &data,Parcel *reply,uint32_t flags)
{
    switch(code){
        case HW_HELLOWORLD2:{//在IBinderTest.h接口中定义
            CHECK_INTERFACE(IBinderTest,data,reply);//检查接口
            const char *str;
            str = data.readCString();
            reply->writeInt32(binderTest(str));//这里调用执行我们定义的binderTest函数
            return NO_ERROR;
        }break;
        default:
            return BBinder::onTransact(code,data,reply,flags);
    }
}
};
