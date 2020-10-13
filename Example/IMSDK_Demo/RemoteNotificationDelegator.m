//
//  RemoteNotificationDelegator.m
//  CustomSDK
//
//  Created by GJS on 2020/8/17.
//

#import "RemoteNotificationDelegator.h"
#import <EBBannerView/EBBannerView.h>
#import "JPUSHService.h"

#import <VP_IMSDK/VP_IMSDK.h>

static RemoteNotificationDelegator *_instance = nil;

@interface RemoteNotificationDelegator ()

@end

@implementation RemoteNotificationDelegator

+ (void)setupRemoteNotificationWithLaunchOptions:(NSDictionary *)launchOptions {
    [JPUSHService setupWithOption:launchOptions appKey:@"f9d28878bacbc01692a65bf1" channel:@"APP STORE" apsForProduction:NO];
}

+ (RemoteNotificationDelegator *)defaultDelegator {
    if (_instance == nil) {
        _instance = [[RemoteNotificationDelegator alloc] init];
    }
    return _instance;
}

- (void)handleDeviceToken:(NSData *)deviceToken {
    
    [JPUSHService registerDeviceToken:deviceToken];
    
 
}

- (void)handleRemoteNotificationUserInfo:(NSDictionary *)userInfo isForeground:(BOOL)isForeground {
    
    // APP处于前台，且当前显示控制器不是对话控制器时显示自定义通知栏
    if (isForeground && ![self.visibleViewController isKindOfClass:VPMessageTableViewController.class]) {
        EBBannerView *banner = [EBBannerView bannerWithBlock:^(EBBannerViewMaker *make) {
            make.object = userInfo;
            make.title = userInfo[@"aps"][@"alert"][@"title"];
            make.content = userInfo[@"aps"][@"alert"][@"body"];
        }];
        
        [banner show];
        
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(localNotificationHandle:) name:EBBannerViewDidClickNotification object:nil];
    } else {
        [self handleRemoteNotificationUserInfo:userInfo];
    }
}

- (void)handleRemoteNotificationUserInfo:(NSDictionary *)userInfo {
    
    
}

- (void)localNotificationHandle:(NSNotification *)notification {
    NSDictionary *userInfo = notification.object;
    [self handleRemoteNotificationUserInfo:userInfo];
}

- (UIViewController *)visibleViewController {
    UIWindow *keyWindow = UIApplication.sharedApplication.keyWindow;
    
    if ([keyWindow.rootViewController isKindOfClass:UITabBarController.class]) {
        UITabBarController *tabbar = (UITabBarController *)keyWindow.rootViewController;
        if ([tabbar.selectedViewController isKindOfClass:UINavigationController.class]) {
            UINavigationController *nav = tabbar.selectedViewController;
            return nav.visibleViewController;
        } else {
            return tabbar.selectedViewController;
        }
    } else if ([keyWindow.rootViewController isKindOfClass:UINavigationController.class]) {
        UINavigationController *nav = (UINavigationController *)keyWindow.rootViewController;
        return nav.visibleViewController;
    } else {
        return keyWindow.rootViewController;
    }
}

@end
