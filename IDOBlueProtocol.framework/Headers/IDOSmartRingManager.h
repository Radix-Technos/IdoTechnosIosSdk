//
//  IDOSmartRingManager.h
//  IDOBlueProtocol
//
//  Created by cyf on 2025/4/1.
//  Copyright © 2025 何东阳. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol IDOSmartRingManagerDelegate <NSObject>

@optional
- (void)smartRingMonitoringHrMeasure:(IDOSetHrMeasureInfoBluetoothModel *)hrMeasureModel;

- (void)smartRingMonitoringSpo2Measure:(IDOSetSpo2MeasureInfoBluetoothModel *)spo2MeasureModel;

- (void)smartRingMonitoringHrMeasureTimeOut;

- (void)smartRingMonitoringSpo2MeasureTimeOut;

- (void)smartRingMonitoringDeviceNotice:(IDO_LISTEN_TYPE)dataType;

@end

/// 智能戒指设置
@interface IDOSmartRingManager : NSObject

@property (nonatomic,weak) id<IDOSmartRingManagerDelegate> delegate;



/**
 * @brief 设置心率测量参数 | Setting measurement parameters
 * @param hrMeasureModel 测量参数 model (IDOSetHrMeasureInfoBluetoothModel)
 * measurement parameters model (IDOSetHrMeasureInfoBluetoothModel)
 * @param callback 设置回调 (errorCode : 0 传输成功,其他值为错误,可以根据 IDOErrorCodeToStr 获取错误码str ; model实时数据和状态)
 * Set callback (errorCode: 0 transmission succeeded, other values are wrong, error code str can be obtained according to IDOErrorCodeToStr;
 * model real-time data and status)
 */
- (void)setHrMeasureCommand:(IDOSetHrMeasureInfoBluetoothModel * _Nullable)hrMeasureModel
                   callback:(void (^ _Nullable)(int errorCode,IDOSetHrMeasureInfoBluetoothModel * _Nullable model))callback;

/**
 * @brief 设置血氧测量参数 | Setting measurement parameters
 * @param spo2MeasureModel 测量参数 model (IDOSetSpo2MeasureInfoBluetoothModel)
 * measurement parameters model (IDOSetSpo2MeasureInfoBluetoothModel)
 * @param callback 设置回调 (errorCode : 0 传输成功,其他值为错误,可以根据 IDOErrorCodeToStr 获取错误码str ; model实时数据和状态)
 * Set callback (errorCode: 0 transmission succeeded, other values are wrong, error code str can be obtained according to IDOErrorCodeToStr;
 * model real-time data and status)
 */
- (void)setSpo2MeasureCommand:(IDOSetSpo2MeasureInfoBluetoothModel * _Nullable)spo2MeasureModel
                     callback:(void (^ _Nullable)(int errorCode,IDOSetSpo2MeasureInfoBluetoothModel * _Nullable model))callback;


- (void)stopTimer;

@end

NS_ASSUME_NONNULL_END
