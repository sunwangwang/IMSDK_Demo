
#import <UIKit/UIKit.h>

#import "VPBaseTableViewCell.h"
#import "VPConfigurationHelper.h"

#import "VPMessageBubbleView.h"
//#import "FITAvatarImageView.h"
#import "FITSystemMessageStyleView.h"

@class VPMessageTableViewCell;

@protocol VPMessageTableViewCellDelegate <NSObject>

@optional
/**
 *  点击多媒体消息的时候统一触发这个回调
 *
 *  @param message   被操作的目标消息Model
 *  @param messageTableViewCell 目标消息在该Cell上
 */
- (void)multiMediaMessageDidSelectedOnMessage:(id <VPMessageModel>)message onMessageTableViewCell:(VPMessageTableViewCell *)messageTableViewCell;

/**
 *  双击文本消息，触发这个回调
 *
 *  @param message   被操作的目标消息Model
 *  @param cell 该目标消息在哪个IndexPath里面
 */
- (void)didDoubleSelectedOnTextMessage:(id <VPMessageModel>)message atCell:(VPMessageTableViewCell *)cell;
/**
 *  点击消息发送者的头像回调方法
 *
 *  @param cell 该目标消息在哪个IndexPath里面
 */
- (void)didSelectedAvatarOnMessage:(id <VPMessageModel>)message atCell:(VPMessageTableViewCell *)cell;

/**
 *  Menu Control Selected Item
 *
 *  @param bubbleMessageMenuSelecteType 点击item后，确定点击类型
 */
- (void)menuDidSelectedAtBubbleMessageMenuSelecteType:(VPBubbleMessageMenuSelecteType)bubbleMessageMenuSelecteType;

- (void)menuDidSelectedForwardingOnMessage:(id<VPMessageModel>)message atCell:(VPMessageTableViewCell *)cell;
- (void)menuDidSelectedDeleteOnMessage:(id<VPMessageModel>)message atCell:(VPMessageTableViewCell *)cell;

- (void)menuDidSelectedResendOnMessage:(id<VPMessageModel>)message atCell:(VPMessageTableViewCell *)cell;

- (VPMessageTextView *)toKeepFirstRespondTextView;

@end

@interface VPMessageTableViewCell : VPBaseTableViewCell

@property (nonatomic, weak) id <VPMessageTableViewCellDelegate> delegate;

/**
 *  自定义多媒体消息内容View
 */
@property (nonatomic, strong) VPMessageBubbleView *messageBubbleView;

/**
 *  头像按钮
 */
@property (nonatomic, strong) UIImageView *avatarImageView;

/**
 *  用户名标签
 */
@property (nonatomic, strong) UILabel *userNameLabel;

@property (nonatomic, strong) FITSystemMessageStyleView *timestampContainer;

/**
 *  获取消息类型
 *
 *  @return 返回消息类型，比如是发送消息，又或者是接收消息
 */
- (VPBubbleMessageType)bubbleMessageType;

/**
 *  初始化Cell的方法，必须先调用这个，不然不会初始化显示控件
 *
 *  @param message          需显示的目标消息Model
 *  @param displayTimestamp 预先告知是否需要显示时间轴Label
 *  @param cellIdentifier   重用Cell的标识
 *
 *  @return 返回消息Cell对象
 */
- (instancetype)initWithMessage:(id <VPMessageModel>)message
              displaysTimestamp:(BOOL)displayTimestamp
                reuseIdentifier:(NSString *)cellIdentifier;

/**
 *  根据消息Model配置Cell的显示内容
 *
 *  @param message          目标消息Model
 *  @param displayTimestamp 配置的时候告知是否需要显示时间轴Label
 */
- (void)configureCellWithMessage:(id <VPMessageModel>)message
               displaysTimestamp:(BOOL)displayTimestamp;

/**
 *  根据消息Model计算Cell的高度
 *
 *  @param message          目标消息Model
 *  @param displayTimestamp 是否显示时间轴Label
 *
 *  @return 返回Cell所需要的高度
 */
+ (CGFloat)calculateCellHeightWithMessage:(id <VPMessageModel>)message
                        displaysTimestamp:(BOOL)displayTimestamp;

@end
