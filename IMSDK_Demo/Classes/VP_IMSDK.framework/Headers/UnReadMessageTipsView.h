//
//  UnReadMessageTipsView.h
//  VP_IMSDK
//
//  Created by 孙旺 on 2020/9/7.
//  Copyright © 2020 孙旺. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UnReadMessageTipsView : UIView
@property (nonatomic ,strong) NSString *unreadCount ;
@property (nonatomic ,assign) BOOL up ; //箭头是向上还是向下
@property (nonatomic ,strong)void(^block)(BOOL up) ;
@end

NS_ASSUME_NONNULL_END
