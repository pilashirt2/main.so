#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>

#define TAG "LudoBluetoothHook"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)

__attribute__((constructor)) void proxy_init() {
    LOGD("Proxy wrapper started. Loading libludobt.so...");
    
    // Apni cheat library load karo
    void* handle_cheat = dlopen("libludobt.so", RTLD_NOW | RTLD_GLOBAL);
    if (!handle_cheat) {
        LOGD("Failed to load libludobt.so: %s", dlerror());
    } else {
        LOGD("SUCCESS: libludobt.so loaded via proxy!");
    }

    // Original game library load karo taaki crash na ho
    void* handle_real = dlopen("libmain_real.so", RTLD_NOW | RTLD_GLOBAL);
    if (!handle_real) {
        LOGD("Failed to load libmain_real.so: %s", dlerror());
    }
}
