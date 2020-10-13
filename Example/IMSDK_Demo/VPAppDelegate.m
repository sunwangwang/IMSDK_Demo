//
//  VPAppDelegate.m
//  IMSDK_Demo
//
//  Created by sunwangwang on 10/09/2020.
//  Copyright (c) 2020 sunwangwang. All rights reserved.
//

#import "VPAppDelegate.h"
#import <VP_IMSDK/VP_IMSDK.h>
#import "VPViewController.h"
#import <Bugly/Bugly.h>

#ifdef NSFoundationVersionNumber_iOS_9_x_Max
#import <UserNotifications/UserNotifications.h>
#endif
#import "RemoteNotificationDelegator.h"
 
@implementation VPAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
   self.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    self.window.backgroundColor = [UIColor whiteColor];
    VPViewController *vc = [VPViewController new];
    UINavigationController *nav = [[UINavigationController alloc]initWithRootViewController:vc];
    self.window.rootViewController = nav;
    [self.window makeKeyAndVisible];
    
    [[ZTIM sharedIM]registerChannelKey:@"f2e546ffd3f25dd3c06f0279595e1c4d" baseUrl: @"http://intelcc-test.icsoc.net"];
    
    application.applicationIconBadgeNumber = 0;
    
    [self registNotificaiton];
    [RemoteNotificationDelegator setupRemoteNotificationWithLaunchOptions:launchOptions];
     [Bugly startWithAppId:@"8fa9b39fef"];
    return YES;
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    
}

/// 注册推送
- (void)registNotificaiton {
    if (@available(iOS 10.0, *)) {
        UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
        center.delegate = self;
        UNAuthorizationOptions options = UNAuthorizationOptionBadge | UNAuthorizationOptionSound | UNAuthorizationOptionAlert;
        [center requestAuthorizationWithOptions:options completionHandler:^(BOOL granted, NSError * _Nullable error) {
            if (granted) {
                
            } else {
                
            }
        }];
    } else if (@available(iOS 8.0, *)) {
        UIUserNotificationType type = UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge;
        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:type categories:nil];
        [UIApplication.sharedApplication registerUserNotificationSettings:settings];
    }
    
    [UIApplication.sharedApplication registerForRemoteNotifications];
}

// iOS10以下收到推送
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    [RemoteNotificationDelegator.defaultDelegator handleRemoteNotificationUserInfo:userInfo isForeground:NO];
    completionHandler(UIBackgroundFetchResultNewData);
}

// iOS10以上应用在前台收到推送
- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler  API_AVAILABLE(ios(10.0)){
    [RemoteNotificationDelegator.defaultDelegator handleRemoteNotificationUserInfo:notification.request.content.userInfo isForeground:YES];
    completionHandler(UNNotificationPresentationOptionSound);
}

// iOS10以上应用在后台收到推送
- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)(void))completionHandler API_AVAILABLE(ios(10.0)) {
    [RemoteNotificationDelegator.defaultDelegator handleRemoteNotificationUserInfo:response.notification.request.content.userInfo isForeground:NO];
    completionHandler();
}

// 注册推送成功后，获得devicetoken
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [RemoteNotificationDelegator.defaultDelegator handleDeviceToken:deviceToken];
}

  
//#pragma mark - UISceneSession lifecycle
//
//- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
//    // Called when a new scene session is being created.
//    // Use this method to select a configuration to create the new scene with.
//    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
//}
//
//- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
//    // Called when the user discards a scene session.
//    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
//    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
//}


@end
