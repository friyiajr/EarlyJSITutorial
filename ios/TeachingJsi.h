#import <React/RCTBridgeModule.h>

#ifdef __cplusplus

#import "react-native-teaching-jsi.h"

#endif

@interface TeachingJsi : NSObject <RCTBridgeModule>

@property(nonatomic, assign) BOOL setBridgeOnMainQueue;

@end
