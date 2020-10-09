//
//  VPFileMessageCell.h
//  VP_IMSDK
//
//  Created by GJS on 2020/8/11.
//  Copyright © 2020 孙旺. All rights reserved.
//

#import "VPBaseTableViewCell.h"
#import "VPMessageUIDefine.h"
#import "VPMessageModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface VPFileMessageCell : VPBaseTableViewCell
@property (nonatomic ,strong)void(^block)(NSString *url);

- (instancetype)initWithMessage:(id <VPMessageModel>)message
                reuseIdentifier:(NSString *)cellIdentifier;

+ (CGFloat)calculateCellHeightWithMessage:(id <VPMessageModel>)message
                        displaysTimestamp:(BOOL)displayTimestamp;
- (void)configureCellWithMessage:(id <VPMessageModel>)message displaysTimestamp:(BOOL)displayTimestamp;
@end

NS_ASSUME_NONNULL_END
