#import "TeachingJsi.h"
#import "react-native-teaching-jsi.h"

#import <React/RCTBridge+Private.h>
#import <React/RCTUtils.h>

#import <jsi/jsi.h>

#import <ReactCommon/CallInvoker.h>

#import <memory>

@implementation TeachingJsi

RCT_EXPORT_MODULE()

@synthesize bridge = _bridge;

+ (BOOL)requiresMainQueueSetup {
  return YES;
}

- (void)setBridge:(RCTBridge *)bridge {
  _bridge = bridge;
  _setBridgeOnMainQueue = RCTIsMainQueue();
  RCTCxxBridge *cxxBridge = (RCTCxxBridge *)self.bridge;

  if(!cxxBridge.runtime) {
    return;
  }

  installMath(*(facebook::jsi::Runtime *) cxxBridge.runtime);
}

@end
