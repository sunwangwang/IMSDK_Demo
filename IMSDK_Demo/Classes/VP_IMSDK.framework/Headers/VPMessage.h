
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "VPMessageModel.h"
#import <UIKit/UIKit.h>
@interface VPMessage : NSObject <VPMessageModel>

/// 缓存cell高度
@property (nonatomic, assign) CGFloat cacheHeight;

@property (nonatomic, copy) NSString *text;
@property (nonatomic, strong)NSArray *contentArr ; //导航的时候下面的一条条内容
@property (nonatomic ,strong) NSString *goodsCount ; //

@property (nonatomic ) BOOL shouldShowMore ;

@property (nonatomic, strong) UIImage *photo;
@property (nonatomic, copy) NSString *thumbnailUrl;
@property (nonatomic, copy) NSString *originPhotoUrl;
@property (nonatomic, assign) CGSize photoSize;

@property (nonatomic, strong) UIImage *videoConverPhoto;
@property (nonatomic, copy) NSString *videoPath;
@property (nonatomic, copy) NSString *videoUrl;
@property (nonatomic, assign) CGSize videoSize;

@property (nonatomic, copy) NSData *voiceData;
@property (nonatomic, copy) NSString *voiceFileID;
@property (nonatomic, copy) NSString *voiceDuration;
@property (nonatomic, assign) VPVoiceMessageReceiveType voiceReceiveType; // 语音文件下载状况

@property (nonatomic, copy) NSString *emotionPath;

@property (nonatomic, strong) UIImage *localPositionPhoto;
@property (nonatomic, copy) NSString *geolocations;
@property (nonatomic, strong) CLLocation *location;

@property (nonatomic, strong) UIImage *avatar;
@property (nonatomic, copy) NSString *avatarUrl;

@property (nonatomic, copy) NSString *sender;

@property (nonatomic, strong) NSDate *timestamp;

@property (nonatomic, assign) BOOL shouldShowUserName;

@property (nonatomic, assign) uint64_t senderId;

@property (nonatomic, assign) BOOL sended;

@property (nonatomic, assign) VPBubbleMessageMediaType messageMediaType;

@property (nonatomic, assign) VPBubbleMessageType bubbleMessageType;

@property (nonatomic) BOOL isRead;

@property (nonatomic, assign) BOOL shouldShowTimeStamp;
@property (nonatomic, assign) BOOL shouldShowLoadingIndicator;
@property (nonatomic, assign) BOOL shouldShowErrorIndicator;


@property (nonatomic )BOOL  shouldShowTimeLabel ; //新版UI上的点击显示时间控件

@property (nonatomic, assign) BOOL voiceReceivingShouldShowLoadingIndicator;

@property (nonatomic, strong) id customData;

@property (nonatomic, assign) CGSize bubbleViewSize;

- (instancetype)initWithText:(NSString *)text
                      sender:(NSString *)sender
                   timestamp:(NSDate *)timestamp;

/**
 *  初始化图片类型的消息
 *
 *  @param photo          目标图片
 *  @param thumbnailUrl   目标图片在服务器的缩略图地址
 *  @param originPhotoUrl 目标图片在服务器的原图地址
 *  @param sender         发送者
 *  @param timestamp    时间咯


 发送时间
 *
 *  @return 返回Message model 对象
 */
- (instancetype)initWithPhoto:(UIImage *)photo
                 thumbnailUrl:(NSString *)thumbnailUrl
               originPhotoUrl:(NSString *)originPhotoUrl
                       sender:(NSString *)sender
                    timestamp:(NSDate *)timestamp;

/**
 *  初始化视频类型的消息
 *
 *  @param videoConverPhoto 目标视频的封面图
 *  @param videoPath        目标视频的本地路径，如果是下载过，或者是从本地发送的时候，会存在
 *  @param videoUrl         目标视频在服务器上的地址
 *  @param sender           发送者
 *  @param timestamp             发送时间
 *
 *  @return 返回Message model 对象
 */
- (instancetype)initWithVideoConverPhoto:(UIImage *)videoConverPhoto
                               videoPath:(NSString *)videoPath
                                videoUrl:(NSString *)videoUrl
                                  sender:(NSString *)sender
                               timestamp:(NSDate *)timestamp;

/**
 *  初始化语音类型的消息
 *
 *  @param voicePath        目标语音的本地路径
 *  @param voiceFileID      目标语音在服务器的fileID
 *  @param voiceDuration    目标语音的时长
 *  @param sender           发送者
 *  @param timestamp             发送时间
 *
 *  @return 返回Message model 对象
 */
- (instancetype)initWithVoicePath:(NSString *)voicePath
                      voiceFileID:(NSString *)voiceFileID
                    voiceDuration:(NSString *)voiceDuration
                           sender:(NSString *)sender
                        timestamp:(NSDate *)timestamp;

/**
 *  初始化语音类型的消息。增加已读未读标记
 *
 *  @param voicePath        目标语音的本地路径
 *  @param voiceFileID      目标语音在服务器的fileID
 *  @param voiceDuration    目标语音的时长
 *  @param sender           发送者
 *  @param timestamp             发送时间
 *  @param isRead           已读未读标记
 *
 *  @return 返回Message model 对象
 */
- (instancetype)initWithVoicePath:(NSString *)voicePath
                      voiceFileID:(NSString *)voiceFileID
                    voiceDuration:(NSString *)voiceDuration
                           sender:(NSString *)sender
                        timestamp:(NSDate *)timestamp
                           isRead:(BOOL)isRead;

/**
 *  初始化gif表情类型的消息
 *
 *  @param emotionPath 表情的路径
 *  @param sender      发送者
 *  @param timestamp   发送时间
 *
 *  @return 返回Message model 对象
 */
- (instancetype)initWithEmotionPath:(NSString *)emotionPath
                             sender:(NSString *)sender
                          timestamp:(NSDate *)timestamp;

/**
 *  初始化地理位置的消息
 *
 *  @param localPositionPhoto 地理位置默认显示的图
 *  @param geolocations       地理位置的信息
 *  @param location           地理位置的经纬度
 *  @param sender             发送者
 *  @param timestamp          发送时间
 *
 *  @return 返回Message model 对象
 */
- (instancetype)initWithLocalPositionPhoto:(UIImage *)localPositionPhoto
                              geolocations:(NSString *)geolocations
                                  location:(CLLocation *)location
                                    sender:(NSString *)sender
                                 timestamp:(NSDate *)timestamp;

@end
