//
//  VPOrderScrollView.h
//  VP_IMSDK
//
//  Created by 孙旺 on 2020/8/1.
//  Copyright © 2020 孙旺. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPMessageModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface VPOrderScrollView : UIView

- (instancetype)initWithModel:(id <VPMessageModel>)message;
- (void)displayInKeyWindow ;
- (void)removeFormKeyWindow ;
@end

NS_ASSUME_NONNULL_END
