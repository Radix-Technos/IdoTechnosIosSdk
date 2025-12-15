//
//  IDOTrackManager.h
//  IDOBlueProtocol
//
//  Created by cyf on 2025/10/13.
//  Copyright © 2025 何东阳. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IDOTrackManager : NSObject

/// 单例
+ (instancetype)shareInstance;


/// 开始添加轨迹路线文件
/// - Parameters:
///   - trackInfoModel: 轨迹路线信息
///   - progressHandler: 文件传输进度回调
///   - completionHandler: 完成回调
- (void)startAddTrackInfo:(IDOV3SetTrackInfoModel *)trackInfoModel
                      progressHandler:(void (^_Nullable)(NSInteger totalProgress))progressHandler
        completionHandler:(void (^_Nullable)(BOOL succeeded,NSInteger errorCode))completionHandle;

- (void)stop;

@end

NS_ASSUME_NONNULL_END
