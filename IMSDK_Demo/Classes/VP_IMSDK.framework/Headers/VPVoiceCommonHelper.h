
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#define AUDIO_LOCAL_FILE @"localfile"

typedef void (^DidDeleteAudioFileBlock)();

@interface VPVoiceCommonHelper : NSObject

/**
 生成文件路径

 @param fileName 文件名

 @return 文件路径
 */
+ (NSString *)createFilePath:(NSString *)fileName;

/**
 获取文件路径

 @param fileName 文件名

 @return 文件路径
 */
+ (NSString *)getFilePath:(NSString *)fileName;

/**
 通过文件路径拿到文件的名字

 @param filePath 文件路径

 @return 文件名
 */
+ (NSString *)getFileNameUsingFilePath:(NSString *)filePath;

/**
 *  判断文件是否存在
 *
 *  @param path 文件路径
 *
 *  @return 存在返回YES
 */
+ (BOOL)fileExistsAtPath:(NSString *)path;

/**
 *  删除文件
 *
 *  @param path 文件路径
 *
 *  @return 成功返回YES
 */
+ (BOOL)deleteFileAtPath:(NSString *)path;

@end
