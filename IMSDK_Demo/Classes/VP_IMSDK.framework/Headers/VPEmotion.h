
#import "VPFoundationMacro.h"

#define kVPEmotionImageViewSize      (VPK_SCREEN_WIDTH / 7 - 10)
#define kVPEmotionMinimumLineSpacing 10
@interface VPEmotion : NSObject

/**
 *  gif表情的封面图
 */
@property (nonatomic, strong) NSString *emotionStr;

/**
 *  gif表情的路径
 */
@property (nonatomic, copy) NSString *emotionPath;

@property (nonatomic ,copy)UIImage *image ;

@end
