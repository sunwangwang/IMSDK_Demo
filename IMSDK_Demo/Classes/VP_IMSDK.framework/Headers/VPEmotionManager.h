#import <Foundation/Foundation.h>
//#import "VPEmotion.h"

@interface VPEmotionManager : NSObject

@property (nonatomic, copy) NSString *emotionName;
/**
 *  某一类表情的数据源
 */
@property (nonatomic, strong) NSMutableArray *emotions;

@end
