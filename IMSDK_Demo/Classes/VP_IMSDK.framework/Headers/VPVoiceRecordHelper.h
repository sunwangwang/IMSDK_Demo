
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef BOOL (^VPPrepareRecorderCompletion)(void);
typedef void (^VPStartRecorderCompletion)(void);
typedef void (^VPStopRecorderCompletion)();
typedef void (^VPPauseRecorderCompletion)(void);
typedef void (^VPResumeRecorderCompletion)(void);
typedef void (^VPCancellRecorderDeleteFileCompletion)(void);
typedef void (^VPRecordProgress)(float progress);
typedef void (^VPPeakPowerForChannel)(float peakPowerForChannel);

@interface VPVoiceRecordHelper : NSObject

@property (nonatomic, copy) VPStopRecorderCompletion maxTimeStopRecorderCompletion;
@property (nonatomic, copy) VPRecordProgress recordProgress;
@property (nonatomic, copy) VPPeakPowerForChannel peakPowerForChannel;
@property (nonatomic, copy, readonly) NSString *recordPath;
@property (nonatomic, assign) CGFloat recordDuration;
@property (nonatomic) float maxRecordTime; // 默认 60秒为最大
@property (nonatomic, readonly) NSTimeInterval currentTimeInterval;

- (void)prepareRecordingWithPath:(NSString *)path prepareRecorderCompletion:(VPPrepareRecorderCompletion)prepareRecorderCompletion;
- (void)startRecordingWithStartRecorderCompletion:(VPStartRecorderCompletion)startRecorderCompletion;
- (void)pauseRecordingWithPauseRecorderCompletion:(VPPauseRecorderCompletion)pauseRecorderCompletion;
- (void)resumeRecordingWithResumeRecorderCompletion:(VPResumeRecorderCompletion)resumeRecorderCompletion;
- (void)stopRecordingWithStopRecorderCompletion:(VPStopRecorderCompletion)stopRecorderCompletion;
- (void)cancelledDeleteWithCompletion:(VPCancellRecorderDeleteFileCompletion)cancelledDeleteCompletion;

@end
