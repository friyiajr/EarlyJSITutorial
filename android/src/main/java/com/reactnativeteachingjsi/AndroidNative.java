package com.reactnativeteachingjsi;

import android.util.Log;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;
import com.facebook.react.turbomodule.core.CallInvokerHolderImpl;

@ReactModule(name = AndroidNative.NAME)
public class AndroidNative extends ReactContextBaseJavaModule {
    public static final String NAME = "AndroidNative";

    private native void installNativeJsi(long jsContextNativePointer);

    public AndroidNative(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    @NonNull
    public String getName() {
        return NAME;
    }

    @ReactMethod(isBlockingSynchronousMethod = true)
    public boolean install(ReactApplicationContext context) {
        try {
            System.loadLibrary("cpp");

            long jsContextPointer = context.getJavaScriptContextHolder().get();

            installNativeJsi(jsContextPointer);

            return true;
        } catch (Exception exception) {
            Log.e(NAME, "Failed to initialize Skia Manager!", exception);
            return false;
        }
    }
}
