//
//  VPFoundationMacro.h
//  VP_IMSDK
//
//  Created by 孙旺 on 2020/7/14.
//  Copyright © 2020 孙旺. All rights reserved.
//

#ifndef VPFoundationMacro_h
#define VPFoundationMacro_h

#import "weakify.h"
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "NSBundle+IMSDK.h"

// device verson float value
#define CURRENT_SYS_VERSION     [[[UIDevice currentDevice] systemVersion] floatValue]

// Size
#define VPK_SCREEN_WIDTH        [[UIScreen mainScreen] bounds].size.width
#define VPK_SCREEN_HEIGHT       [[UIScreen mainScreen] bounds].size.height

// iPad
#define kIsiPad                 (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//phone
#define kIs_iPhone              (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

#define IS_IPHONE_X \
    ({ BOOL isPhoneX = NO; \
       if (@available(iOS 11.0, *)) { \
           isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0; \
       } \
       (isPhoneX); })

#define TopHeight               (IS_IPHONE_X ? 88 : 64)
#define StatusHeight            (IS_IPHONE_X ? 44 : 20)
#define BottomHeight            (IS_IPHONE_X ? 83 : 49)
#define SAFE_Bottom_Height     (IS_IPHONE_X ? 34 : 0)

/// 资源文件的bundle路径
#define AssetBundlePath \
        [[NSBundle mainBundle].resourcePath stringByAppendingPathComponent:@"IMSDK.bundle"]

/// 资源文件的bundle
#define AssetBundle \
        [NSBundle bundleWithPath:AssetBundlePath]

/// 从资源文件获取图片
#define Image(name) \
        [UIImage imageWithContentsOfFile:[AssetBundlePath stringByAppendingPathComponent:[NSString stringWithFormat:@"%@", name]]]


/// 获取本地化的字符串
#define LocalizedString(key) \
[NSBundle localizedStringForKey:key]
      //  NSLocalizedStringFromTableInBundle(key, @"IMSDKLocalize", AssetBundle, nil)
/// 弹出文本提示框
#define Alert(TITLE, MESSAGE, VIEWCONTROLLER)\
        UIAlertController *macroAlert = [UIAlertController alertControllerWithTitle:TITLE message:MESSAGE preferredStyle:UIAlertControllerStyleAlert];\
        [macroAlert addAction:[UIAlertAction actionWithTitle:LocalizedString(@"confirm") style:UIAlertActionStyleCancel handler:nil]];\
        [VIEWCONTROLLER presentViewController:macroAlert animated:YES completion:nil];
/// 表情文本对照文件名
#define emotionImageFileName \
        [NSLocale.preferredLanguages.firstObject containsString:@"zh"] ? @"IMSDK.bundle/emotionImage" : @"IMSDK.bundle/emotionImageEN"

#define kVoiceRecorderTotalTime 60.0

#endif /* VPFoundationMacro_h */
