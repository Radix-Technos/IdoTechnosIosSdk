//
//  IDOOfflineMapManager.h
//  IDOBlueProtocol
//
//  Created by cyf on 2025/9/16.
//  Copyright © 2025 何东阳. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, IDOOfflineMapState) {
    IDOOfflineMapStateInvalidMapName = 1,//无效地图名称
    IDOOfflineMapStateInvalidResource = 2,//无效资源
    IDOOfflineMapStateInsufficientSpace = 3,//空间不足
    IDOOfflineMapStateUnzipResourceFailed = 4,//解压资源失败
    IDOOfflineMapStateQueryConfigFailed = 5,//查询地图配置失败
    IDOOfflineMapStateQueryMapInfoFailed = 6,//查询地图详情失败
    IDOOfflineMapStateSetMapInfoFailed = 7,//设置地图信息(名称、总大小、文件列表等)失败
    IDOOfflineMapStateAddFailed = 8,//失败
    IDOOfflineMapStateAddSuccess = 9,//成功
    IDOOfflineMapStateDeleteMapInfoFailed = 10,//删除地图失败
    IDOOfflineMapStateDeviceisSports = 11,//设备处于运动中，请结束运动后结束重试
    IDOOfflineMapStateDeviceisCall = 12,//设备处于通话中，请结束通话后重试
    IDOOfflineMapStateDevicePowerSaving = 13 //设备正在处于省电模式
};

@interface IDOOfflineMapManager : NSObject

/// 单例
+ (instancetype)shareInstance;


/// 开始添加离线地图文件
/// - Parameters:
///   - mapName: 离线地图名称
///   - fileZipPath: 离线地图zip压缩包
///   - progressHandler: 所有文件传输进度回调
///   - completionHandler: 完成回调
- (void)startAddOfflineMapWithMapName:(NSString *)mapName
                          fileZipPath:(NSString *)fileZipPath
                      progressHandler:(void (^_Nullable)(NSInteger totalProgress))progressHandler
                    completionHandler:(void (^_Nullable)(BOOL succeeded, IDOOfflineMapState state))completionHandler;

- (void)stop;

@end
NS_ASSUME_NONNULL_END
