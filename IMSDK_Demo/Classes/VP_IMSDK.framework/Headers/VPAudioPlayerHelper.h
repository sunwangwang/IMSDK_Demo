
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface VPAudioPlayerHelper : NSObject <AVAudioPlayerDelegate>

@property (nonatomic, strong) AVAudioPlayer *player;

+ (id)shareInstance;

- (AVAudioPlayer *)player;
- (BOOL)isPlaying;

- (void)managerAudioWithData:(NSData *)voiceData toPlay:(BOOL)toPlay;
- (void)pausePlayingAudio;//暂停
- (void)stopAudio;//停止

@end
