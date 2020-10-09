
#import <Foundation/Foundation.h>

 
@interface VPConfigurationHelper : NSObject

@property (nonatomic, strong, readonly) NSArray *popMenuTitles;

@property (nonatomic, strong, readonly) NSDictionary *messageInputViewStyle;

@property (nonatomic, strong, readonly) NSDictionary *messageTableStyle;

//根据后台返回的一堆参数来做适配
@property (nonatomic, strong) NSString * msgBackgroundUri ; //主题图片
@property (nonatomic, strong) NSString * msgBackgroundColor ; //主题色（当设定主题图片时，优先取主题图片）
@property (nonatomic, assign) float msgListViewDividerHeight ; //消息列表消息项间距
@property (nonatomic, assign) BOOL hideLeftAvatar ; //显示左侧(客服消息)头像
@property (nonatomic, assign) BOOL hideRightAvatar ; //显示右侧(访客消息)头像
@property (nonatomic, strong) NSString *avatarShape ; //头像形状
@property (nonatomic, strong) NSString *tipsTextColor ; //系统提示类消息的字体颜色（包括分配客服消息，消息时间标签等）
@property (nonatomic, assign) float tipsTextSize ; //系统提示类消息的字体大小（包括分配客服消息，消息时间标签等）
@property (nonatomic, strong) NSString *msgItemBackgroundLeft ; //消息气泡：左边消息项背景,同时影响文本和语音消息。
@property (nonatomic, strong) NSString *msgItemBackgroundRight ; //消息气泡：右边消息项背景, 同时影响文本和语音消息。
@property (nonatomic, strong) NSString *textLeftMsgColor ; //左文本消息字体颜色
@property (nonatomic, strong) NSString *textRightMsgColor ; //右文本消息字体颜色
@property (nonatomic, assign) float textLeftMsgSize ; //左文本消息字体大小
@property (nonatomic, assign) float textRightMsgSize ; //右文本消息字体大小
@property (nonatomic, strong) NSString *hyperLinkColor ; //链接类消息字体颜色
@property (nonatomic, strong) NSString *titleBackgroundResId ; //标题栏背景图
@property (nonatomic, strong) NSString *titleBackgroundColor ; //标题栏背景颜色，如果同时设置 图片 和颜色，优先使用图片
@property (nonatomic, strong) NSString *titleContentColor; // 标题颜色
@property (nonatomic, assign) float titleContentSize; // 标题大小
 
@property (nonatomic, strong) NSString *actionButtonTextColor ; //输入区上方按钮 按钮文字颜色
@property (nonatomic, strong) NSString *actionButtonBorderColor ; //输入区上方按钮 按钮边框颜色
@property (nonatomic, assign) BOOL  hideEmoji ; //显示表情按钮
@property (nonatomic, assign) BOOL hidePhotographButton ; //显示拍照按钮
@property (nonatomic, assign) BOOL hideAudio ; //显示语音切换按钮
@property (nonatomic, assign) BOOL hideSendPictureButton ; //显示发送图片按钮
@property (nonatomic, assign) BOOL hideKeyboardOnEnterConsult ; //在进入聊天界面时是否隐藏输入键盘
@property (nonatomic, strong) NSString *topTipTextColor ; //会话窗口上方提示条字体颜色
@property (nonatomic, assign) float topTipTextFontSize ; //会话窗口上方提示条字体大小
@property (nonatomic, strong) NSString *topTipBackgroundColor ; //会话窗口上方提示条背景颜色

@property (nonatomic ,assign)float  avatarImageSize_Left  ; //左边头像
@property (nonatomic ,assign)float  avatarImageSize_Right  ; //右边头像
+ (instancetype)appearance;

-(void)setAvatarImageSize ;
- (void)setupPopMenuTitles:(NSArray *)popMenuTitles;

// The key from (Input Tool Bar Style Key)
- (void)setupMessageInputViewStyle:(NSDictionary *)messageInputViewStyle;

// The key from (Message Table Style Key)
- (void)setupMessageTableStyle:(NSDictionary *)messageTableStyle;

@end
