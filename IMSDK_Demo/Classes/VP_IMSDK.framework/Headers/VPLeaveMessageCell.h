//
//  VPLeaveMessageCell.h
//  VP_IMSDK
//
//  Created by 孙旺 on 2020/8/12.
//  Copyright © 2020 孙旺. All rights reserved.
//

 #import <UIKit/UIKit.h>
#import "VPBaseTableViewCell.h"
#import "VPMessageModel.h"

NS_ASSUME_NONNULL_BEGIN
@class VPLeaveMessageCell ;

@protocol VPLeaveMessageCellDelegate <NSObject>

@optional

- (void)didSelectedLeaveMessageBtnOnMessage:(id <VPMessageModel>)message atCell:(VPLeaveMessageCell *)cell;

@end

@interface VPLeaveMessageCell : VPBaseTableViewCell

@property (nonatomic, weak) id <VPLeaveMessageCellDelegate> delegate;

- (instancetype)initWithMessage:(id <VPMessageModel>)message

                reuseIdentifier:(NSString *)cellIdentifier;

+ (CGFloat)calculateCellHeightWithMessage:(id <VPMessageModel>)message displaysTimestamp:(BOOL)displayTimestamp;
- (void)configureCellWithMessage:(id <VPMessageModel>)message displaysTimestamp:(BOOL)displayTimestamp;
@end

NS_ASSUME_NONNULL_END
