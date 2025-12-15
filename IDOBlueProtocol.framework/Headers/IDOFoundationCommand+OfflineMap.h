//
//  IDOFoundationCommand+OfflineMap.h
//  IDOBlueProtocol
//
//  Created by cyf on 2025/9/13.
//  Copyright © 2025 何东阳. All rights reserved.
//

#import <Foundation/Foundation.h>
#if __has_include(<IDOBlueProtocol/IDOBlueProtocol.h>)
#else
#import "IDOBindEnum.h"
#import "IDOBluetoothBaseModel.h"
#import "IDOGetInfoBluetoothModel.h"
#import "IDOSetInfoBluetoothModel.h"
#import "IDODataExchangeModel.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface IDOFoundationCommand (OfflineMap)


/// 设置离线地图授权码
/// - Parameters:
///   - authModel: 授权码模型
///   - callback:  设置后回调 (errorCode : 0 传输成功,其他值为错误,可以根据 IDOErrorCodeToStr 获取错误码str)
+ (void)setOfflineMapAuthCodeCommand:(IDOV3SetOfflineMapAuthCodeModel * _Nullable)authModel
                     callback:(void (^_Nullable)(int errorCode))callback;

/// 获取离线地图授权信息
/// - Parameter callback: 执行后回调 data (IDOGetV3OfflineMapAuthModel) (errorCode : 0 传输成功,其他值为错误,可以根据 IDOErrorCodeToStr 获取错误码str)
///  callback data (IDOGetV3OfflineMapAuthModel) (errorCode : 0 The transfer was successful, the other values are errors, and the error code str can be obtained according to IDOErrorCodeToStr)
+ (void)getOfflineMapAuthInfoCommand:(void (^_Nullable)(int errorCode, IDOGetV3OfflineMapAuthModel * _Nullable model))callback;



/// 添加单个地图
/// - Parameters:
///   - authModel: 地图详情模型
///   - callback:  设置后回调 (errorCode : 0 传输成功,其他值为错误,可以根据 IDOErrorCodeToStr 获取错误码str)
+ (void)addSingleOfflineMapCommand:(IDOV3SetOfflineMapInfoModel * _Nullable)mapInfoModel
                     callback:(void (^_Nullable)(int errorCode))callback;


/// 获取单个地图细信息
/// - mapNameMdel: 地图名字详情模型
/// - Parameter callback: 执行后回调 data (IDOGetV3OfflineMapAuthModel) (errorCode : 0 传输成功,其他值为错误,可以根据 IDOErrorCodeToStr 获取错误码str)
///  callback data (IDOGetV3OfflineMapAuthModel) (errorCode : 0 The transfer was successful, the other values are errors, and the error code str can be obtained according to IDOErrorCodeToStr)
+ (void)getSingleOfflineMapCommand:(IDOV3SetOfflineMapNameModel * _Nullable)mapNameModel  callback:(void (^_Nullable)(int errorCode, IDOGetV3OfflineMapInfoReplyModel * _Nullable model))callback;

/// 获取固件离线地图的配置信息详情
/// - Parameter callback: 执行后回调 data (IDOGetV3OfflineMapAuthModel) (errorCode : 0 传输成功,其他值为错误,可以根据 IDOErrorCodeToStr 获取错误码str)
///  callback data (IDOGetV3OfflineMapAuthModel) (errorCode : 0 The transfer was successful, the other values are errors, and the error code str can be obtained according to IDOErrorCodeToStr)
+ (void)getOfflineMapConfigCommandCallback:(void (^_Nullable)(int errorCode, IDOGetV3OfflineMapInfoReplyModel * _Nullable model))callback;


/// 删除地图
/// - mapNameMdel: 地图名字详情模型
/// - Parameter callback:  设置后回调 (errorCode : 0 传输成功,其他值为错误,可以根据 IDOErrorCodeToStr 获取错误码str)
+ (void)deleteOfflineMapCommand:(NSArray<IDOV3SetOfflineMapNameModel *> * _Nullable)mapNameItems   callback:(void (^_Nullable)(int errorCode))callback;

/// 添加单个轨迹路线
/// - Parameters:
///   - authModel: 轨迹路线信息模型
///   - callback:  设置后回调 (errorCode : 0 传输成功,其他值为错误,可以根据 IDOErrorCodeToStr 获取错误码str)
+ (void)addTrackCommand:(IDOV3SetTrackInfoModel * _Nullable)trackModel
               callback:(void (^_Nullable)(int errorCode))callback;

@end

NS_ASSUME_NONNULL_END
