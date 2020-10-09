
#import <UIKit/UIKit.h>
#import "VPMessageBubbleFactory.h"

#define kVPBubblePhotoMargin 8.0f // 上下左右的边距

@interface VPBubblePhotoImageView : UIImageView

/**
 *  加载网络图片的时候，需要用到转圈的控件
 */
@property (nonatomic, strong) UIActivityIndicatorView *activityIndicatorView;

- (void)configureMessagePhoto:(UIImage *)messagePhoto thumbnailUrl:(NSString *)thumbnailUrl originPhotoUrl:(NSString *)originPhotoUrl onBubbleMessageType:(VPBubbleMessageType)bubbleMessageType;

/**
 *  获取消息类型比如发送或接收
 *
 *  @return 消息类型
 */
- (VPBubbleMessageType)getBubbleMessageType;

@end
