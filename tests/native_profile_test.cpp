#include "ios_build_guard.hpp"
#include <cassert>
#include <cstring>
int main(){
    using namespace vt::ios;
    assert(nativeProfile("unknown")==nullptr);
    assert(nativeProfile("ptg.vng")==&vngProfile);
    assert(nativeProfile("com.vng.playtogether")==&vngProfile);
    assert(nativeProfile("com.haegin.playtogether")==&globalProfile);
    assert(std::strcmp(vngProfile.uuid,globalProfile.uuid)!=0);
    for(auto*p:{&vngProfile,&globalProfile}){
        auto reader=[&](std::uintptr_t rva,unsigned char*out,std::size_t n){
            for(std::size_t i=0;i<p->count;++i)if(p->guards[i].rva==rva){
                std::memcpy(out,p->guards[i].bytes,n);return true;
            }
            return false;
        };
        assert(verifyNativeSpans(*p,0x10000000,reader));
        assert(!verifyNativeSpans(*p,16,reader));
        assert(!verifyNativeSpans(*p,0x10000000,[](auto,auto,auto){return false;}));
        assert(!verifyNativeSpans(*p,0x10000000,[&](auto rva,auto out,auto n){
            bool ok=reader(rva,out,n);out[0]^=1;return ok;
        }));
        auto*other=p==&vngProfile?&globalProfile:&vngProfile;
        assert(!verifyNativeSpans(*other,0x10000000,reader));
    }
}
