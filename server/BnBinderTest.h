#include "../common/IBinderTest.h"

namespace android{

class BnBinderTest: public BnInterface<IBinderTest>//继承BnInterface
{
public:
    //onTransact此函数在BnBinderTest.cpp中具体实现，它用于处理来自client端对应的请求
    virtual status_t onTransact(uint32_t code,const Parcel &data,Parcel *reply,uint32_t flags =0);
};
};
