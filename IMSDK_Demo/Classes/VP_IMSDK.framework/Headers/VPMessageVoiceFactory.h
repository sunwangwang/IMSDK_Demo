
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VPMessageBubbleFactory.h"

@interface VPMessageVoiceFactory : NSObject

+ (UIImageView *)messageVoiceAnimationImageViewWithBubbleMessageType:(VPBubbleMessageType)type;

@end
