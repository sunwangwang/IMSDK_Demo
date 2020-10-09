
#import <UIKit/UIKit.h>

@protocol VPMessageTableViewDelegate <NSObject>

@optional

- (void)loadMoreMessagesScrollTotopAndCompleted:(void (^)( NSArray *, BOOL))completed;


@end

@interface VPMessageTableView : UITableView
@property (nonatomic, weak) id <VPMessageTableViewDelegate> tableViewDelegate;

- (void)setDisablePullToRefresh:(BOOL)disablePullToRefresh ;
@end
