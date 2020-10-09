//
//  VPServiceTypeCell.h
//  VP_IMSDK
//
//  Created by 孙旺 on 2020/7/23.
//  Copyright © 2020 孙旺. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPBaseTableViewCell.h"
#import "VPMessageModel.h"
NS_ASSUME_NONNULL_BEGIN
@class VPServiceTypeCell;

@protocol VPServiceTypeCellDelegate <NSObject>

@optional

- (void)didSelectedMoreBtnOnOrderMessage:(id <VPMessageModel>)message atCell:(VPServiceTypeCell *)cell;

@end

@interface VPServiceTypeCell : VPBaseTableViewCell

@property (nonatomic, weak) id <VPServiceTypeCellDelegate> delegate;

- (instancetype)initWithMessage:(id <VPMessageModel>)message

                reuseIdentifier:(NSString *)cellIdentifier;

+ (CGFloat)calculateCellHeightWithMessage:(id <VPMessageModel>)message displaysTimestamp:(BOOL)displayTimestamp;
- (void)configureCellWithMessage:(id <VPMessageModel>)message displaysTimestamp:(BOOL)displayTimestamp;
@end

NS_ASSUME_NONNULL_END
