
#import "VPBaseTableViewCell.h"
#import "VPMessageUIDefine.h"
#import "VPMessageModel.h"

@interface VPSystemMessageCell : VPBaseTableViewCell

- (instancetype)initWithReuseIdentifier:(NSString *)cellIdentifier;

+ (CGFloat)calculateCellHeightWithMessage:(id <VPMessageModel>)message displaysTimestamp:(BOOL)displayTimestamp;
- (void)configureCellWithMessage:(id <VPMessageModel>)message displaysTimestamp:(BOOL)displayTimestamp;

@end
