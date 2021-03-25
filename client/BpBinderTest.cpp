#include <binder/Parcel.h>
#include "BpBinderTest.h"
#include <utils/Log.h>

namespace android{

status_t BpBinderTest::binderTest(const char *str)
{
    Parcel data,reply;
    data.writeInterfaceToken(IBinderTest::getInterfaceDescriptor());
    data.writeCString(str);
    //通过code调用远程BinderTest方法，传递data
    status_t status = remote()->transact(HW_HELLOWORLD2,data,&reply);
    if(status != NO_ERROR){
        ALOGE("BinderTest error: %s",strerror(-status));
    }else{
        status = reply.readInt32();
    }
    return status;
}

BpBinderTest::BpBinderTest(const sp<IBinder>& impl): BpInterface<IBinderTest>(impl){}

};
