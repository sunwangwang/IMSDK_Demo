//
//  ZTIM.h
//  VP_IMSDK
//
//  Created by 孙旺 on 2020/8/19.
//  Copyright © 2020 孙旺. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^CompletionBlock)(BOOL register);

@interface ZTIM : NSObject
@property (nonatomic ,strong) NSString *baseUrl ; //主域名

//单例sdk
+ (instancetype)sharedIM ;

/**
*
*
*  sdk初始化
*
*  @param channelKey  app在平台注册后的唯一标识
*
* 返回值 BOOL = YES 表示成功
 baseUrl  三方的主域名
 
*/

- (BOOL)registerChannelKey:(NSString *)channelKey baseUrl:(NSString *)baseUrl ;

/**
*
*
*  sdk初始化
*
*  @param name  用户名
 @param avatar  头像地址
 @param thirdId  用户在这个sdk里面唯一标示
 @param pushId  appSDK推送别名
  
 @param otherInfo   用户自定义信息 格式： ，json字符串  样式：[{\"key\":\"姓名\"，\"value\":\"小明\"}]
  
*
*
 
*/


-(void)loginWithUsername:(NSString *)name avatar:(NSString *)avatar thirdId:(NSString *)thirdId fromId:(NSString *)pushId  otherUserData:(NSString *)otherInfo subId:(NSString *)subId channeKey:(NSString *)channeKey completion:(CompletionBlock)block ;

//退出登陆的时候调用
-(void)loginOut ;
@end

NS_ASSUME_NONNULL_END
