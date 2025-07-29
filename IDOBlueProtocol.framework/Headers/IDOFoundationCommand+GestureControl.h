//
//  IDOFoundationCommand+GestureControl.h
//  IDOBlueProtocol
//
//  Created by cyf on 2025/4/7.
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



@interface IDOFoundationCommand (GestureControl)


/// 设置戒指手势控制 | Set the ring gesture control
/// @param model IDOV3SetGestureControlModel
/// @param callback 设置后回调 (errorCode : 0 传输成功,其他值为错误,可以根据 IDOErrorCodeToStr 获取错误码str)
/// Set post callback (errorCode : 0 transfer succeeds, other values are wrong, you can get error code str according to IDOErrorCodeToStr)
+ (void)setGestureControlCommand:(IDOV3SetGestureControlModel *_Nullable)model
                        callback:(void (^_Nullable)(int errorCode))callback;


/**
 * @brief 获取戒指手势控制 | Gets the ring gesture control
 * @param callback 设置后回调 (errorCode : 0 传输成功,其他值为错误,可以根据 IDOErrorCodeToStr 获取错误码str)
 * Set post callback (errorCode : 0 transfer succeeds, other values are wrong, you can get error code str according to IDOErrorCodeToStr)
 */
+ (void)getGestureControlCommand:(void (^_Nullable)(int errorCode, IDOV3SetGestureControlModel * _Nullable model))callback;


/**
 * @brief 获取戒指手势控制 | Gets the ring gesture control
 * @param callback 设置后回调 (errorCode : 0 传输成功,其他值为错误,可以根据 IDOErrorCodeToStr 获取错误码str)
 * Set post callback (errorCode : 0 transfer succeeds, other values are wrong, you can get error code str according to IDOErrorCodeToStr)
 */
+ (void)getGestureControSupportConfigCommand:(void (^_Nullable)(int errorCode, IDOV3SetGestureControlModel * _Nullable model))callback;


@end

NS_ASSUME_NONNULL_END
