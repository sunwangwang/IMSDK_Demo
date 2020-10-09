
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "VPMessageBubbleFactory.h"
#import <UIKit/UIKit.h>

@class VPMessage;

@protocol VPMessageModel <NSObject>

@required
@property (nonatomic, assign) CGFloat cacheHeight;
- (NSString *)text;
- (NSString *)goodsCount;
 -(NSArray *)contentArr ;
- (UIImage *)photo;
- (NSString *)thumbnailUrl;
- (NSString *)originPhotoUrl;

- (UIImage *)videoConverPhoto;
- (NSString *)videoPath;
- (NSString *)videoUrl;
- (VPVoiceMessageReceiveType)voiceReceiveType;

- (NSData *)voiceData;
- (NSString *)voiceFileID;
- (NSString *)voiceDuration;

- (UIImage *)localPositionPhoto;
- (NSString *)geolocations;
- (CLLocation *)location;

- (NSString *)emotionPath;

- (UIImage *)avatar;
- (NSString *)avatarUrl;

- (CGSize)photoSize;
- (CGSize)videoSize;

- (VPBubbleMessageMediaType)messageMediaType;

- (VPBubbleMessageType)bubbleMessageType;

- (uint64_t)senderId;

- (CGSize)bubbleViewSize;
- (id)customData;

@optional

- (BOOL)shouldShowUserName;
- (BOOL)shouldShowLoadingIndicator;
- (BOOL)shouldShowErrorIndicator;
- (BOOL)shouldShowTimeStamp;
- (BOOL)shouldShowMore;
- (BOOL)voiceReceivingShouldShowLoadingIndicator;
- (BOOL)voiceReceivedFailureShouldShowErrorIndicator;
- (BOOL)shouldShowTimeLabel;
- (void)setShouldShowTimeLabel:(BOOL)shouldShowTimeLabel;
- (void)setShouldShowMore:(BOOL)shouldShowMore;
- (NSString *)sender;

- (NSDate *)timestamp;

- (BOOL)isRead;
- (void)setIsRead:(BOOL)isRead;
-(void)setContentArr:(NSArray *)arr;
@end
