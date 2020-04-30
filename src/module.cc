#include <node_api.h>

napi_value MyFunction(napi_env env, napi_callback_info info) {
    napi_value data;
    napi_create_int32(env, 10, &data);

    return data;
}

napi_value Init(napi_env env, napi_value exports) {
    napi_status status;
    napi_value fn;

    status = napi_create_function(env, NULL, 0, MyFunction, NULL, &fn);

    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to wrap function");
    }

    status = napi_set_named_property(env, exports, "my_function", fn);
    
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to populate exports");
    }

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)