#include "../common/IBinderTest.h"

namespace android{

class BpBinderTest: public BpInterface<IBinderTest>
{
public:
    BpBinderTest(const sp<IBinder>& impl);
    virtual status_t binderTest(const char *str);
};
};
