
#import <UIKit/UIKit.h>

// Views
#import "VPMessageTextView.h"
#import "VPMessageInputView.h"
#import "VPBubblePhotoImageView.h"

#import "FLAnimatedImageView.h"
#import "FLAnimatedImage.h"

// Macro
#import "VPFoundationMacro.h"

// Model
#import "VPMessage.h"

// Factorys
#import "VPMessageVoiceFactory.h"

#define kVPMessageBubbleDisplayMaxLine 200

#define kVPTextLineSpacing             3.0
@protocol VPMessageBubbleViewDeleagte <NSObject>

- (void)onReSendClick;

@end

@interface VPMessageBubbleView : UIView

@property (nonatomic, weak) id<VPMessageBubbleViewDeleagte> delegate;
/**
 *  目标消息Model对象
 */
@property (nonatomic, strong, readonly)  id <VPMessageModel> message;

/**
 *  用于显示气泡的ImageView控件
 */
@property (nonatomic, weak, readonly) UIImageView *bubbleImageView;
+ (CGSize)getBubbleFrameWithMessage:(id <VPMessageModel>)message;

/**
 *  用于显示语音的控件，并且支持播放动画
 */
@property (nonatomic, weak, readonly) UIImageView *animationVoiceImageView;

/**
 *  用于显示语音未读的控件，小圆点
 */
@property (nonatomic, weak, readonly) UIImageView *voiceUnreadDotImageView;

/**
 *  用于显示语音时长的label
 */
@property (nonatomic, weak, readonly) UILabel *voiceDurationLabel;

/**
 *  用于显示仿微信发送图片的控件
 */
@property (nonatomic, weak, readonly) VPBubblePhotoImageView *bubblePhotoImageView;

/**
 *  显示语音播放的图片控件
 */
@property (nonatomic, weak, readonly) UIImageView *videoPlayImageView;

/**
 *  设置文本消息的字体
 */
//@property (nonatomic, strong) UIFont *font UI_APPEARANCE_SELECTOR;

@property (nonatomic, strong) UIActivityIndicatorView *indicatorView;
@property (nonatomic, strong) UIButton *errorIndicatorButton;

/**
 *  初始化消息内容显示控件的方法
 *
 *  @param frame   目标Frame
 *  @param message 目标消息Model对象
 *
 *  @return 返回VPMessageBubbleView类型的对象
 */
- (instancetype)initWithFrame:(CGRect)frame
                      message:(id <VPMessageModel>)message;

+ (UIFont *)font:(VPBubbleMessageType)type ;
/**
 *  获取气泡相对于父试图的位置
 *
 *  @return 返回气泡的位置
 */
- (CGRect)bubbleFrame;

/**
 *  根据消息Model对象配置消息显示内容
 *
 *  @param message 目标消息Model对象
 */
- (void)configureCellWithMessage:(id <VPMessageModel>)message;

/**
 *  根据消息Model对象计算消息内容的高度
 *
 *  @param message 目标消息Model对象
 *
 *  @return 返回所需高度
 */
+ (CGFloat)calculateCellHeightWithMessage:(id <VPMessageModel>)message;

/**
*
*  获取文本
*
*/
- (NSString *)displayTextViewText;

@end
