
#import <UIKit/UIKit.h>
#import "VPEmotion.h"

#define kVPEmotionCollectionViewCellIdentifier @"VPEmotionCollectionViewCellIdentifier"
#define kVPEmotionCollectionViewFooterIdentifier @"VPEmotionCollectionViewFooterIdentifier"

@interface VPEmotionCollectionViewCell : UICollectionViewCell

/**
 *  需要显示和配置的gif表情对象
 */
@property (nonatomic, strong) VPEmotion *emotion;

@property (nonatomic, retain) UILabel *emotionLabel;
@property (nonatomic ,strong) UIImageView *emotionView ;

@end
