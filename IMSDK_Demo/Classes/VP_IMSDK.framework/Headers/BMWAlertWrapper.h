//
//  BMWAlertWrapper.h
//  MiaoWan
//
//  Created by Zhiyang Fu on 11/9/15.
//  Copyright © 2015 4c. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BMWAlertWrapper : NSObject

+ (void)presentAlert:(NSString *)title
             message:(NSString *)message
   cancelButtonTitle:(NSString *)cancelButtonTitle
   otherButtonTitles:(NSArray *)otherButtonTitles
touchedButtonAtIndex:(void (^)(NSInteger buttonIndex))block;

+ (void)presentAlert:(NSString *)title
             message:(NSString *)message
   cancelButtonTitle:(NSString *)cancelButtonTitle
   otherButtonTitles:(NSArray *)otherButtonTitles
destructiveButtonTitles:(NSArray *)destructiveButtonTitle
touchedButtonAtIndex:(void (^)(NSInteger buttonIndex))block;

+ (void)presentActionSheet:(NSString *)title
         cancelButtonTitle:(NSString *)cancelButtonTitle
    destructiveButtonTitle:(NSString *)destructiveButtonTitle
         otherButtonTitles:(NSArray<NSString *> *)otherButtonTitles
      touchedButtonAtIndex:(void (^)(NSInteger buttonIndex))block;

@end
