
#import <Foundation/Foundation.h>

#import <AVFoundation/AVFoundation.h>

@interface VPVideoOutputSampleBufferFactory : NSObject

+ (UIImage *)imageFromSampleBuffer:(CMSampleBufferRef)sampleBuffer;

@end
