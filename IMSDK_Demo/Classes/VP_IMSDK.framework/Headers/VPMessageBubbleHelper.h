
#import <Foundation/Foundation.h>

@interface VPMessageBubbleHelper : NSObject

+ (instancetype)sharedMessageBubbleHelper;

- (NSAttributedString *)bubbleAttributtedStringWithText:(NSString *)text isSend:(BOOL)isHost;
@end
