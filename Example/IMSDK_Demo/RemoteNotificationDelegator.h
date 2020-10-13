//
//  RemoteNotificationDelegator.h
//  CustomSDK
//
//  Created by GJS on 2020/8/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RemoteNotificationDelegator : NSObject

+ (void)setupRemoteNotificationWithLaunchOptions:(NSDictionary *)launchOptions;
+ (RemoteNotificationDelegator *)defaultDelegator;
/// 处理推送注册后获得的deviceToken
/// @param deviceToken deviceToken
- (void)handleDeviceToken:(NSData *)deviceToken;
/// 处理推送内容
/// @param userInfo 推送内容
/// @param isForeground 应用是否在前台收到推送
- (void)handleRemoteNotificationUserInfo:(NSDictionary *)userInfo isForeground:(BOOL)isForeground;

@end

NS_ASSUME_NONNULL_END
