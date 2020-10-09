
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM (NSInteger, VPBubbleMessageType) {
    VPBubbleMessageTypeSending = 0, // 发送
    VPBubbleMessageTypeReceiving // 接收
};

typedef NS_ENUM (NSUInteger, VPBubbleImageViewStyle) {
    VPBubbleImageViewStyleWeChat = 0
};

typedef NS_ENUM (NSUInteger, VPVoiceMessageReceiveType) {
    VPVoiceMessageReceiveTypeSuccess   = 0,   // 语音消息下载成功
    VPVoiceMessageReceiveTypeReceiving = 1,   // 语音消息下载中
    VPVoiceMessageReceiveTypeFailure   = 2,   // 语音消息下载失败
};

typedef NS_ENUM (NSInteger, VPBubbleMessageMediaType) {
    VPBubbleMessageMediaTypeText          = 0,
    VPBubbleMessageMediaTypePhoto         = 1,
    VPBubbleMessageMediaTypeVideo         = 2,
    VPBubbleMessageMediaTypeVoice         = 3,
    VPBubbleMessageMediaTypeEmotion       = 4,
    VPBubbleMessageMediaTypeLocalPosition = 5,
    VPBubbleMessageMediaTypeSystem        = 6,
    VPBubbleMessageMediaTypeDelimiter      = 7 ,
    VPBubbleMessageMediaTypeGoods      = 8 ,
    VPBubbleMessageMediaTypeService      = 9 , //
    VPBubbleMessageMediaTypeSystem_LeaveMessage        = 10,
    VPBubbleMessageMediaTypeFile      = 11 , //
    VPBubbleMessageMediaTypeCard  = 12 ,
    VPBubbleMessageMediaTypeAttribute  = 13 , //富文本
    
};

typedef NS_ENUM (NSInteger, VPBubbleMessageMenuSelecteType) {
    VPBubbleMessageMenuSelecteTypeTextCopy        = 0,
    VPBubbleMessageMenuSelecteTypeTextTranspond   = 1,
    VPBubbleMessageMenuSelecteTypeTextFavorites   = 2,
    VPBubbleMessageMenuSelecteTypeTextMore        = 3,

    VPBubbleMessageMenuSelecteTypePhotoCopy       = 4,
    VPBubbleMessageMenuSelecteTypePhotoTranspond  = 5,
    VPBubbleMessageMenuSelecteTypePhotoFavorites  = 6,
    VPBubbleMessageMenuSelecteTypePhotoMore       = 7,

    VPBubbleMessageMenuSelecteTypeVideoTranspond  = 8,
    VPBubbleMessageMenuSelecteTypeVideoFavorites  = 9,
    VPBubbleMessageMenuSelecteTypeVideoMore       = 10,

    VPBubbleMessageMenuSelecteTypeVoicePlay       = 11,
    VPBubbleMessageMenuSelecteTypeVoiceFavorites  = 12,
    VPBubbleMessageMenuSelecteTypeVoiceTurnToText = 13,
    VPBubbleMessageMenuSelecteTypeVoiceMore       = 14,
};

@interface VPMessageBubbleFactory : NSObject

+ (UIImage *)bubbleImageViewForType:(VPBubbleMessageType)type
    style:(VPBubbleImageViewStyle)style
meidaType:(VPBubbleMessageMediaType)mediaType   ;

@end
