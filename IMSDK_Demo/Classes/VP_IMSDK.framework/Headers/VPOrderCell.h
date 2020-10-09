
#import <UIKit/UIKit.h>
#import "VPBaseTableViewCell.h"
#import "VPMessageModel.h"
NS_ASSUME_NONNULL_BEGIN
@class VPOrderCell;
@protocol VPOrderCellDelegate <NSObject>

@optional

- (void)didSelectedMoreBtnOnOrderMessage:(id <VPMessageModel>)message atCell:(VPOrderCell *)cell;

@end

@interface VPOrderCell : VPBaseTableViewCell

@property (nonatomic, weak) id <VPOrderCellDelegate> delegate;

- (instancetype)initWithMessage:(id <VPMessageModel>)message

                reuseIdentifier:(NSString *)cellIdentifier;

+ (CGFloat)calculateCellHeightWithMessage:(id <VPMessageModel>)message displaysTimestamp:(BOOL)displayTimestamp;
- (void)configureCellWithMessage:(id <VPMessageModel>)message displaysTimestamp:(BOOL)displayTimestamp;

@end

NS_ASSUME_NONNULL_END
