#include<binder/Parcel.h>
#include"BnBinderTest.h"
#include<utils/Log.h>
 
namespace android {
 
class BinderTestService: public BnBinderTest//继承
{
public:
    static void instantiate();
    virtual status_t binderTest(const char *str);//实现接口IBinderTest的函数，这些是我们自己需要实现的一些功能函数
    virtual status_t onTransact(uint32_t code,const Parcel &data,Parcel *reply,uint32_t flags = 0);
 
private:
    BinderTestService();
    virtual ~BinderTestService();
};
};
