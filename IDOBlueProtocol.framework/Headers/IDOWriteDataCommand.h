//
//  IDOWriteDataCommand.h
//  IDOBlueProtocol
//
//  Created by cyf on 2024/11/13.
//  Copyright © 2024 何东阳. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IDOWriteDataCommand : NSObject

+ (IDOWriteDataCommand *)shareInstance;

/// 外设根据特征值发送蓝牙数据
/// - Parameters:
///   - data: cmd data
///   - characteristic: 特征值
///   - type: CBCharacteristicWriteType
- (void)writeValue:(NSData *)data forCharacteristic:(CBCharacteristic *)characteristic type:(CBCharacteristicWriteType)type;

- (void)setCloseDeviceFunctionCommand;

@end

NS_ASSUME_NONNULL_END
